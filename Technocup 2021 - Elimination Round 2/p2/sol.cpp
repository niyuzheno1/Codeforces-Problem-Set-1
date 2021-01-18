#include <iostream>
#include <vector>
#include <string>

using namespace std;

#define MAXN 100010
#define MAXC 110

int ne[MAXN][MAXC];
int c[MAXN];

int main()
{
    #ifndef ONLINE_JUDGE
        freopen("input.txt","r",stdin);
        freopen("output.txt","w",stdout);
    #endif
    int tcases; 
    cin >> tcases;
    for(int jj = 0; jj < tcases; ++ jj){
        int n,k;
        cin >> n >>k;
        for(int i = 0; i < n+1; ++i)
            for(int j = 0; j< MAXC; ++j)
                ne[i][j] = n;
        for(int i = 0; i < n; ++i)
            cin >> c[i];
        for(int i = n-1; i >= 0; --i){
            ne[i][c[i]] = i;
            for(int j = 1; j <= 100; ++j)
                if(j != c[i])
                    ne[i][j] = ne[i+1][j];
        }
        int ans = n+1;
        for(int color = 1; color <= 100; ++ color){
            int pos = -1;
            int ansx = 0;
            while(pos < n){
                int nex = pos+1;
                if(nex >= n)
                    break;
                int minpos = n;
                for(int i = 1; i < 100; ++i)
                    if(i != color && ne[nex][i] != -1)
                        minpos = min(minpos, ne[nex][i]);
                if(minpos == n)
                    break;
                pos = minpos;
                pos += k-1;
                ++ansx;
            }
            if (ansx < ans) ans = ansx;
        }
        cout << ans <<endl;
    }
    return 0;
}