#include <iostream>
#include <vector>
#include <string>
#include <map>
using namespace std;

#define mp make_pair
typedef long long ll;
typedef pair<ll,ll> pii;
#define X first
#define Y second
#define MAXN 100010
pii getsum(ll x, ll y, ll d){
    ll sum = 0;
    ll cnt = 0;
    ll u = x;
    while(x%y == 0 && cnt <= d){
        cnt = cnt + 1;
        sum += u;
        x/=y;
    }
    return mp(sum,cnt);
}


ll a[MAXN];
pii b[MAXN];


int main()
{
    #ifndef ONLINE_JUDGE
        freopen("input.txt","r",stdin);
        freopen("output.txt","w",stdout);
    #endif
    int tcases;
    cin >> tcases;
    while(tcases--){
        int n;
        ll x;
        cin >> n >> x;
        for(int i = 0; i < n; ++i){
            cin >> a[i];
            b[i] = mp(0,0);
        }
        for(int i = 0; i < n; ++i)
            b[i] = getsum(a[i],x,a[i]);
        ll u = b[0].Y;
        int idx = 0;
        for(int i = 0; i < n; ++i)
        {
            if(u > b[i].Y)
            {
                idx = i;
                u = b[i].Y;
            }
        }
        ll ans = 0;
        for(int i = 0; i <n;++i){
            ll ux = 0;
            if(i > idx)
                ux = getsum(a[i],x,u-1).X + a[i];
            else
                ux = getsum(a[i],x,u).X + a[i];
            ans += ux;
        }
        cout << ans <<endl;
    }
    return 0;
}