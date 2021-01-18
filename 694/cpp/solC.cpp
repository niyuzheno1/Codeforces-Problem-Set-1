#include <iostream>
#include <vector>
#include <string>
#include <queue>
using namespace std;
#define mp make_pair
typedef long long ll;
typedef pair<ll,ll> pii;
#define X first
#define Y second
#define MAXN 300010
ll f[MAXN];
ll c[MAXN];
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
        int m;
        cin >> n >> m;
        priority_queue<pii> pq;
        for(int i = 0; i < n; ++i){
            ll x; cin >> x;
            --x;
            pq.push(mp(x,(long long)i));
            f[i] = 0;
        }
        for(int i = 0; i < m; ++i)
            cin >> c[i];
        for(int i = 0; i < m; ++i){
            if(pq.empty()) continue;
            while(!pq.empty()){
                auto x = pq.top(); pq.pop();
                if(x.X > ((ll)i)){
                    f[((int)x.Y)] = c[i];
                    break;
                }else{
                    f[((int)x.Y)] = c[((int)x.X)]; 
                }
            }
            if(pq.empty()) continue;
        }
        ll ans = 0;
        for(int i = 0; i < n; ++i){
            ans += f[i];
        }
        cout << ans << endl;
    }

    return 0;
}