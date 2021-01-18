#include <iostream>
#include <vector>
#include <string>

using namespace std;

#define MAXN 100010
int previous[MAXN][34];
int nexts[MAXN][34];
int a[MAXN];
int xsum[MAXN];

int main()
{
    #ifndef ONLINE_JUDGE
        freopen("input.txt","r",stdin);
        freopen("output.txt","w",stdout);
    #endif
    int n; 
    cin >> n;
    for(int i = 0; i < n ; ++ i){
        cin >> a[i];
    }
    xsum[0] = a[0];
    for(int i = 1; i < n; ++i)
        xsum[i] = xsum[i-1] ^ a[i];
    xsum[n] = xsum[n-1];
    for(int i = 0; i < n; ++i){
        int x = a[i];
        for(int j = 0; j < 32; ++j){
            int prev = i == 0 ? -1: previous[i-1][j];
            if((1<<j) & x){
                previous[i][j] = i;
            }else{
                previous[i][j] = prev;
            }
        }
    }
    for(int i = n-1; i >= 0; --i){
        int x = a[i];
        for(int j = 0; j <= 32; ++j){
            int ne = i == n-1? n : nexts[i+1][j];
            if(((1<<j) & x) == 0){
                nexts[i][j] = i;
            }else{
                nexts[i][j] = ne;
            }
        }
    }
    int ans = n + 10;
    for(int i = 0; i < n-1; ++i){
        int x = a[i], y = a[i+1];
        for(int j = 31; j >= 0; --j){
            int nj = j;
            if((x &(1<<j)) == 0 && (y &(1<<j)) != 0){
                int prev = previous[i][j];
                while(prev >= 0){
                    int diff = 0;
                    if (prev > 0)
                        diff = xsum[prev-1];
                    int all = xsum[i] ^ diff;
                    if(all > y)
                        ans = min(ans, i-prev);
                    nj = nj - 1;
                    prev = prev > 0 ? previous[prev-1][nj] : -1;
                }
                break;
            }
        }
    }
    
    for(int i = n-1; i > 0; --i){
        int x = a[i], y = a[i-1];
        for(int j = 31; j >= 0; --j){
            int nj = j;
            if((x &(1<<j)) != 0 && (y &(1<<j)) == 0){
                int ne = nexts[i][j];
                while(ne < n){
                    int diff = i > 0 ? xsum[i-1] : 0 ;
                    int all = diff ^ xsum[ne];
                    if(all < y)
                        ans = min(ans, ne - i );
                    nj = j - 1;
                    ne = ne < n-1 ? nexts[ne+1][nj] : n;
                }
                break;
            }
        }
    }
    if(ans > n)
    {
        cout << "-1" <<endl;
        return 0;
    }
    cout << ans <<endl;
    return 0;
}