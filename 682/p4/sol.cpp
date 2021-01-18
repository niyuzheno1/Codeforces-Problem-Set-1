#include <iostream>
#include <vector>
#include <string>

using namespace std;

typedef struct op{
    int x;
    int y;
    int z;
}o;

void add(int x, int y, int z, op & u){
    u.x = x;
    u.y = y; 
    u.z = z;
}

vector<o> vo;
#define MAXN 100010
int a[MAXN];

int main()
{
    #ifndef ONLINE_JUDGE
        freopen("input.txt","r",stdin);
        freopen("output.txt","w",stdout);
    #endif
    int n ;
    cin >> n;
    for(int i = 0; i < n; ++i){
        cin >> a[i];
    }
    for(int i = 0; i < n; ++i){
        int stopping = n-1;
        for(int j = 0; j < n-2; ++j){
            if(a[j] != a[j + 1]){
                int u = a[j]^a[j + 1]^a[j+2];
                a[j] = u;
                a[j+1] = u;
                a[j+2] = u;
                op tmp;
                add(j,j +1, j + 2,tmp);
                vo.push_back(tmp);
                stopping = j;
                break;
            }
            
           if(vo.size() > n)
            break;
        }
        for(int j = stopping; j > 0; --j){
            if(a[j] != a[j-1] && j-1 > 0){
                op tmp;
                int u = a[j] ^ a[j-1]^a[j-2];
                a[j] = u; a[j-1] = u; a[j-2] = u;
                add(j-2,j-1, j,tmp);
                vo.push_back(tmp);
                
            }
            
            if(vo.size() > n)
            break;
        }
        if(vo.size() > n)
            break;
    }
    bool flag = true; 
    for(int i = 1; i < n; ++i){
        if(a[i] != a[i-1]){
            flag = false;
        }
    }
    if(flag && vo.size() <= n){
        cout << "YES" << endl;
        cout << vo.size() <<endl;
        for(int i = 0; i < vo.size(); ++i){
            cout << vo[i].x + 1<< " " << vo[i].y +1 << " " << vo[i].z +1<< endl;
        }
    }else{
        cout << "NO" <<endl;
    }
    return 0;
}