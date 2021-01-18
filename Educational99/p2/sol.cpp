#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <queue>

using namespace std;
#define MAXN 1000010

int f[MAXN * 2];
typedef pair<int,int> pii;
void compute(){
    queue<pii> qe;
    qe.push(make_pair(0,1));
    for(int i = 0; i < 2*MAXN; ++i)
        f[i] = 2*MAXN;
    f[0] = 0;
    while(!qe.empty()){
        pii u = qe.front();
        qe.pop();
        int y = u.first;
        int k = u.second;
        if(y + k < 2*MAXN){
            if(f[y+k] > f[y] + 1){
                f[y+k] = f[y] + 1;
                qe.push(make_pair(y+k,k+1));
            }
        }
        if( f[y-1] > f[y] + 1){
                f[y-1] = f[y] + 1;
                qe.push(make_pair(y-1,k+1));
        }
        
    }
}
void compute2(bool & changed, int upper ,int lower){
    bool firsttime = !changed;
    changed = false;
    for(int st = lower; st <= 0; ++ st){
        for(int i = st, k = -st + 1; i < upper; i += k,++k)
            if(i > 0){
                if(f[i] > k-1 && i < MAXN){
                    changed =  true; 
                }
                f[i] = min(f[i],k-1);
            }
        
    }
    for(int i = upper -2; i >= 0; --i){
        if(f[i] > f[i+1]+1 && i < MAXN){
                    changed =  true;
        }
        f[i] = min(f[i+1]+1, f[i]);
    }
    
}

int main()
{
    #ifndef ONLINE_JUDGE
        freopen("input.txt","r",stdin);
        freopen("output.txt","w",stdout);
    #endif
    bool c = false;
    for(int i = 0; i < MAXN*2; ++i)
        f[i] = 2*MAXN;
    compute2(c, 2* MAXN, -MAXN*2);
    // cout << c << endl;
    // compute2(c, 2*MAXN, -3*MAXN);
    // cout << c << endl;
    
    int tcases;
    cin >> tcases;
    for(int i = 0; i < tcases; ++i){
        int x; cin >> x;
        cout << f[x] << endl;
    }
    return 0;
}