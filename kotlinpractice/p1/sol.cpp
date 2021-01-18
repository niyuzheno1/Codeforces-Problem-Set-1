#include <iostream>
#include <vector>
#include <string>

using namespace std;

int label[3000];
int planksize[1010];

int main()
{
    #ifndef ONLINE_JUDGE
        freopen("input.txt","r",stdin);
        freopen("output.txt","w",stdout);
    #endif
    int n,m,d;
    cin >> n >> m >> d;
    for(int i = 0 ; i < m; ++i)
        cin >> planksize[i];
    int st = 0, tow = d;
    for(int i = d; i < n + 1 && st < m; ){
        if(label[i] == 0){
            for(int j = 0; j < planksize[st]; ++ j){
                label[i+j] = st+1;
                tow = max(i+j+d, tow);
            }
            ++st;
            i += d;
        }
    }
    if(tow < n+1 ){
        cout << "NO" <<endl;
        return 0;
    }
    cout << "YES" <<endl;
        
    for(int i = n+1; st < m; ++ st){
        while(label[i] != 0)
            ++i;
        for(int j = 0; j < planksize[st]; ++ j){
            label[i] = st+1;
            ++i;
        }
    }

    int cnt = 0, ed = 0;
    for(ed = n+1; ed < 3*n; ++ed){
        if(label[ed] == 0)
            break;
        ++cnt;
    }
    while(cnt > 0){
        int i = 0;
        for( i = n; i > 0; --i){
            if(label[i] == 0)
                break;
        }
        for(int j = i; j < ed; ++ ed){
            label[j] = label[j+1];
        }
        --cnt;
    }
    for(int i = 1; i <= n; ++i)
        cout << label[i] << ' ';
    cout <<endl;   
    return 0;
}