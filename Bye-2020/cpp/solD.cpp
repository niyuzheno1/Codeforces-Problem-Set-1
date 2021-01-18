#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include <map>
using namespace std;

typedef long long ll;

typedef pair<ll,ll> pii;
#define X first
#define Y second
#define mp make_pair

int main()
{
    #ifndef ONLINE_JUDGE
        freopen("input.txt","r",stdin);
        freopen("output.txt","w",stdout);
    #endif
    int tcases;
    cin >> tcases;
    while(tcases--){
        int n; cin >> n;
        vector<ll> w(n+1,0);
        ll sums = 0;
        for(int i = 0; i < n; ++i){
             cin >> w[i];
             sums += w[i];
        }
        vector<ll> d(n+1,0);
        for(int i = 0; i < n-1; ++i){
            int x,y;
            cin >> x>>y;
            ++d[x-1];
            ++d[y-1];
        }  
        priority_queue<pii> pq;
        for(int i = 0; i < n; ++i)
            pq.push(mp(w[i],d[i]-1));
        vector<ll> op;
        op.push_back(sums);
        while(!pq.empty()){
            auto x = pq.top();
            if(x.Y == 0)
            {
                pq.pop();
                continue;
            }
            pq.pop();
            op.push_back(x.X + sums);
            sums = x.X + sums;
            pq.push(mp(x.X,x.Y-1));
        }
        for(int i = 0; i < op.size(); ++i){
            cout << op[i] << " ";
        }
        cout <<endl;
    }

    return 0;
}