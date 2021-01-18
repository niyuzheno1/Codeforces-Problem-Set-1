#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;
typedef long long ll;
ll gcd(ll a, ll b) {
   if (b == 0)
   return a;
   return gcd(b, a % b);
}

vector<ll> a; 
vector<ll> b; 



int main()
{
    #ifndef ONLINE_JUDGE
        freopen("input.txt","r",stdin);
        freopen("output.txt","w",stdout);
    #endif
    int n, m; cin >> n >> m;
    for(int i = 0; i < n; ++i)
    {
        ll x; cin >> x;
        a.push_back(x);
    }
    for(int i = 0; i < m; ++i)
    {
        ll x; cin >> x;
        b.push_back(x);
    }
    sort(a.begin(),a.end());
    sort(b.begin(),b.end());
    auto brutal = [&] (){
            for(int i = 0; i < m; ++i)
            {
                ll x = b[i];
                ll ans = a[0]+x;
                for(int j = 0; j < n; ++ j)
                    ans = gcd(ans, a[j]+x);
                cout << ans << " ";
            }
    };
    if(n >= 3){
        ll base = gcd(a[1]-a[0], a[2]-a[0]);
        for(int j = 1; j < n; ++j)
            base = gcd(base, a[j]-a[0]);
        for(int i = 0; i < m; ++i){
            cout << gcd(a[0]+b[i],base) << " ";
        }
    }else{
        brutal();
    }

    cout << endl;
    return 0;
}