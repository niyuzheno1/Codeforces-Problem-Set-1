#include <iostream>
#include <vector>
#include <string>
#include <cmath>

using namespace std;
typedef long long ll;
int main()
{
    #ifndef ONLINE_JUDGE
        freopen("input.txt","r",stdin);
        freopen("output.txt","w",stdout);
    #endif
    int tcases;
    cin >> tcases; 
    for(int jj = 0; jj < tcases; ++ jj){
        ll n;
        cin >> n;
        ll ans = n, ansn = 1;
        ll x = sqrt(n)+2;
        for(ll i = 2; i < x;++i){
            if((n % i) == 0){
                ll cnt = 0;
                ll y = n;
                while((y%i) == 0){
                    ++cnt;
                    y /= i;
                } 
                if (cnt > ansn){
                    ansn = cnt;
                    ans = i;
                }
            }
        }
        cout << ansn << endl;
        while(ansn > 1){
            cout << ans << " ";
            n /= ans;
            ansn -- ;
        }
        cout << n << endl;
    }
    return 0;
}