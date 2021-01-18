#include <iostream>
#include <vector>
#include <string>

using namespace std;
typedef long long ll;
#define BITL 59
#define MODN 1000000007

inline ll add(ll  x, ll  y){
    if(x+y >= MODN){
        return x+y -MODN;
    }
    return x+y;
}
inline  ll mul(ll  x, ll  y){
    return (x*y)%MODN;
}

ll bitlen[BITL+5];

inline ll mb(ll  x){
    return x%MODN;
} 
ll div2(ll x){
    return mul(x,500000004LL)%MODN;
}

#define MAXN 500010
int n; 
ll v[MAXN];

inline ll pairbitwiseandt(int pos){
        int m = n;
        ll ans = 0;
        for(ll i = BITL; i >= 0; --i){
            ll k = 0;
            ll l = 0;
            for(int j = 0; j < n; ++j){
                if(((v[j] >>  i) & 1LL)){
                    if( pos >= 0 && ((v[j]>>pos) & 1LL))
                        ++k;
                    if(pos <0)
                        ++k;
                }
            }
            for(int j = 0; j < m; ++j){
                if(((v[j] >>  i) & 1LL))
                    ++l;
            }
            ans = add(ans, mul(mul(mb(1LL<<i) ,k), l));
        }
        return ans;
}
int main()
{
    #ifndef ONLINE_JUDGE
        freopen("input.txt","r",stdin);
        freopen("output.txt","w",stdout);
    #endif
    ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);

    int tcases;
    cin >> tcases;
    while(tcases --){
        
        cin >> n;
        
        for(int i = 0; i < n; ++i){
            ll x; cin >> x; v[i] = x;
        }
        ll plain = pairbitwiseandt(-1);
        for(ll i = 0; i <= BITL; ++i){
            bitlen[i] = (pairbitwiseandt( i));
        }
        ll ans = 0;
        for(ll i = 0; i <= BITL; ++i){
            for(int j = 0; j < n; ++j){
                if((v[j]>>i) & 1LL){
                    //bitwise and
                    ans = add(ans, mul(plain, mb(1LL<<i)));
                }else{
                    ans = add(ans, mul(bitlen[i], mb(1LL<<i)));
                }
            }
        }
        cout << ans <<endl;
    }
    return 0;
}