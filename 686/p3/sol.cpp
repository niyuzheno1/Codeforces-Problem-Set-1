#include <iostream>
#include <vector>
#include <string>

using namespace std;

#define MAXN 200010

int b[MAXN];
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
        int n ;
        cin >> n;
        for(int i = 0; i <= n+2;++i){
            b[i] = -1;
            c[i] = 0;
        }
        for(int i = 0; i < n;++i)
        {
            int x;
            cin >> x;
            if(b[x] != i-1)
                c[x] = c[x] + 1;
            b[x] = i;
        }
        int ans = n+2;
        for(int i = 0; i <= n;++i)
        {
            if(b[i] != -1){
                if(b[i] == n-1)
                    ans = min(ans,c[i]);
                else
                    ans = min(ans,c[i]+1);                
            }
        }
        cout << ans << endl;
    }
    return 0;
}