#include <iostream>
#include <vector>
#include <string>

using namespace std;

  
int max(int a, int b);
#define MAXN 6000  
int L[MAXN][MAXN]; 
/* Returns length of LCS for X[0..m-1], Y[0..n-1] */
int lcs( char *X, char *Y, int m, int n , int lastx, int lasty )  
{  
     
    int i, j;  
    for (i = lastx; i <= m; i++)  
    {  
        for (j = lasty; j <= n; j++)  
        {  
        if (i == 0 || j == 0)  
            L[i][j] = 0;  
      
        else if (X[i - 1] == Y[j - 1])  
            L[i][j] = L[i - 1][j - 1] + 1;  
        else
            L[i][j] = max(L[i - 1][j], L[i][j - 1]);  
        }  
    }  
          
    return L[m][n];  
}  
  
/* Utility function to get max of 2 integers */
int max(int a, int b)  
{  
    return (a > b)? a : b;  
}  
    
  
// This code is contributed by rathbhupendra 

int main()
{
    #ifndef ONLINE_JUDGE
        freopen("input.txt","r",stdin);
        freopen("output.txt","w",stdout);
    #endif
    int n,m;
    cin >> n >> m;
    string a,b;
    cin >> a >>b;
    int ans = 0;
    int inci = 0, incj = 0;
    for(int i = 0; i < n; ){
        inci = 1;
        for(int j = 0; j < m; )
        {
            incj = 1;
            int l = i;
            int k = j;
            int lastl = 0;
            int lastk = 0;
            while(l < n && k < m){
                l += 8;
                k += 8;
                int xx = min(n, l);
                int yy = min(m, k);
                xx = xx - i + 1;
                yy = yy - j + 1;
                lcs(&a[i], &b[j], xx, yy, lastl, lastk);
                int cur = -5000*5000;
                for(int u = lastl; u < xx; ++u)
                    for(int v = lastk; v < yy;  ++ v){
                        cur = max(cur, 4* L[u][v] - u - v );
                    }

                if(cur < 0){
                    break;
                }
                else
                {
                    ans = max(ans,cur);
                }
                
                inci = max(L[xx-1][yy-1],1);
                incj = max(L[xx-1][yy-1],1);
                lastl = xx;
                lastk = yy;
            }
            
            if(incj > 1){
                incj /= 2;
            }
            j += incj;
        }
        if(inci > 1){
            inci /= 2;
        }
        i += inci;
    }
   

    cout << ans << endl;
    return 0;
}