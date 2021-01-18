#include <iostream>
#include <vector>
#include <string>
#include <cstring>
using namespace std;
#define MAXN 510
int m,n;
char g[MAXN][MAXN];
int tleft[MAXN][MAXN];
int ext[MAXN][MAXN];
int main()
{
    #ifndef ONLINE_JUDGE
        freopen("input.txt","r",stdin);
        freopen("output.txt","w",stdout);
    #endif

    int tcases; 
    cin >> tcases;
    for(int jj = 0; jj < tcases; ++ jj){
        cin >> n >> m;
        memset(g, 0, sizeof(g));
        memset(tleft, 0, sizeof(tleft));
        memset(ext, 0, sizeof(ext));
        for(int i = 0; i < n; ++ i){
            string x; cin >> x;
            for(int j = 0; j < m; ++j)
                g[i][j] = x[j];
        }
        for(int i = 0; i < n; ++ i){
            for(int j = m-1; j >= 0; --j){
                if(g[i][j] == '.')
                    tleft[i][j] = 0;
                else
                    tleft[i][j] = tleft[i][j+1] + 1;
            }
        }
        for(int i = 0; i < n; ++ i){
            for(int j = 0; j < m; ++ j){
                if(g[i][j] == '.'){
                    ext[i][j] = 0;
                    continue;
                }
                for(int k = 0; k < n-i; ++ k){
                    if( j-k < 0) break;
                    if(tleft[i+k][j-k] < 2*k + 1) break;
                    ext[i][j] = k+1; 
                }
            }
        }
        int ans = 0;
        for(int i = 0; i < n; ++ i)
            for(int j = 0; j < m; ans +=  ext[i][j] , ++ j);
        cout << ans <<endl;
    } 
    return 0;
}