#include <iostream>
#include <vector>
#include <string>

using namespace std;
#define MAXN 110
int a[2][MAXN];
int f[2][MAXN];
int res[MAXN];

int main()
{
    #ifndef ONLINE_JUDGE
        freopen("input.txt","r",stdin);
        freopen("output.txt","w",stdout);
    #endif
    int tcases;
    cin >> tcases;
    while(tcases--){
        int n,m;
        cin >> n;
        for(int i = 0; i < n; ++i){
            int x; 
            cin >> x;
            a[0][i] = x;
            f[0][i] = 0;
        }
        cin >> m;
        
        for(int i = 0; i < m; ++i){
            int x; 
            cin >> x;
            a[1][i] = x;
            f[1][i] = 0;
        }
        for(int i = n-1; i >= 0; -- i){
            f[0][i] = f[0][i+1];
            f[0][i] = max(0,f[0][i] + a[0][i]);
        }
        
        for(int i = n-1; i >= 0; -- i){
            f[1][i] = f[1][i+1];
            f[1][i] = max(0,f[1][i] + a[1][i]);
        }
        int fpt = 0, spt = 0;
        for(int i = 0; i < n+m; ++i){
            if(fpt == n){
                res[i] = a[1][spt]; 
                ++spt;
                continue;
            }
            else if(spt == m){
                res[i] = a[0][fpt]; 
                ++fpt;
                continue;
            }
            if(f[0][fpt] > f[1][spt]){
                res[i] = a[0][fpt];
                ++fpt;
            }
            else{
                res[i] = a[1][spt];
                ++spt;
            }
        }
        int ans = 0, sum = 0;
        for(int i = 0; i < n + m ; ++ i){
            sum += res[i];
            ans = max(ans, sum);
            
        }
        cout << ans <<endl;
    }
    return 0;
}