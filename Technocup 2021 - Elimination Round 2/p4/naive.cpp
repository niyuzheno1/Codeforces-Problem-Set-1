#include <iostream>
#include <vector>
#include <string>

using namespace std;

#define MAXN 100010
int xsum[MAXN];
int main()
{
    #ifndef ONLINE_JUDGE
        freopen("input.txt","r",stdin);
        freopen("output.txt","w",stdout);
    #endif
    int tcases; 
    cin >> tcases;
    for(int jj = 0; jj < tcases; ++ jj){
        int n;
        cin >> n;
        vector<int> a;
        for(int i = 0; i < n; ++i){
            int x = 0;
            cin >> x;
            a.push_back(x);
        }
        xsum[0] = a[0];
        for(int i = 1; i < n; ++i)
            xsum[i] = xsum[i-1] ^ a[i];
        int ans = n + 10;
        for(int i = 0; i < n; ++i){
            for(int j = i; j < n; ++j){
                int diff = 0;
                if(i - 1 >= 0)
                    diff = xsum[i-1];
                int tmp1 = xsum[j]^diff; 
                if(i != 0){
                    if(tmp1 < a[i-1])
                        ans = min(ans, j-i+1);
                }
                if(j != n-1){
                    if(tmp1 > a[j+1])
                        ans = min(ans, j-i+1);
                }
            }
        }
        if(ans > n) ans = -1;
        cout << ans <<endl;
    }
    return 0;
}