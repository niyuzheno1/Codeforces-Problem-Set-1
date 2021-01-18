#include <iostream>
#include <vector>
#include <string>
#include <queue>
using namespace std;
#define MAXN 200010
#define TMAX 200020*2
vector<int> G[MAXN];
vector<int> RG[MAXN];
int dist[MAXN];
int dp[MAXN];
int mdp[MAXN];

int main()
{
    #ifndef ONLINE_JUDGE
        freopen("input.txt","r",stdin);
        freopen("output.txt","w",stdout);
    #endif
    int tcases; cin >>tcases;
    while(tcases--){
        int n, m;
        cin >> n >> m;
        for(int i = 0; i < n; ++i){
            dp[i] = TMAX;
            mdp[i] = TMAX;
            dist[i] = TMAX;
            G[i].clear();
            RG[i].clear();
        }
        dist[0] = dp[0] = mdp[0] = 0;
        for(int i = 0; i < m ; ++i){
                int u,v;
                cin >> u >> v;
                --u,--v;
                G[u].push_back(v);
                RG[v].push_back(u);
        }
        queue<int> q;
        q.push(0);
        while(!q.empty()){
            int u = q.front(); q.pop();
            for(int i = 0; i < G[u].size(); ++i){
                int v = G[u][i];
                if(dist[v] > dist[u] + 1){
                    dist[v] = dist[u] + 1;
                    q.push(v);
                }
            }
        }
        q.push(0);
        while(!q.empty()){
            int u = q.front(); q.pop();
            for(int i = 0; i < RG[u].size(); ++i){
                int v = RG[u][i];
                if(dist[v] > dist[u]){
                    if(mdp[v] > dist[u]){
                        mdp[v] = dist[u];
                        q.push(v);
                    }
                }else{
                    if(mdp[v] == TMAX){
                        mdp[v] = dist[v];
                        q.push(v);
                    }
                }
            }
        }
        for(int i = 0; i < n; ++i){
            cout << min(mdp[i], dist[i]) << ' ' ;
        }
        cout <<endl;
    }
    return 0;
}