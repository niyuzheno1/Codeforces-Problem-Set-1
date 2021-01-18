#include <iostream>
#include <vector>
#include <string>

using namespace std;

#define MAXN 300010

int a[MAXN];
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
        int n; cin >> n;
        for(int i = 1; i <= n; ++i) cin >> a[i];
        for(int i = 1; i <= n; ++i){
            int flag = 1;
            for(int j = 1; j <= n; ++j){
                c[flag] = a[j];
                ++flag;
            }
            sort(c,c+flag);
            
        }
    }
    return 0;
}