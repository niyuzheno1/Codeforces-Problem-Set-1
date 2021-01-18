#include <iostream>
#include <vector>
#include <string>
#include <queue>
using namespace std;
#define MAXN 300010
bool visited[MAXN];
int deg[MAXN];
vector<int> e[MAXN];
bool selected[MAXN];
#define mp make_pair
typedef int ll;
typedef pair<ll,ll> pii;
#define X first
#define Y second

void dfs(int x){
    if(visited[x]) return;
    visited[x] = 1;
    for(int i = 0; i < e[x].size(); ++i){
        dfs(e[x][i]);
    }
}

bool connectivity(int n){
    dfs(0);
    for(int i = 0; i < n; ++ i){
        if(visited[i] == 0)  return false;
        visited[i] = 0;
    }
    return true;
}

int main()
{
    #ifndef ONLINE_JUDGE
        freopen("input.txt","r",stdin);
        freopen("output.txt","w",stdout);
    #endif
    int tcases;
    cin >> tcases;
    while(tcases--){
        int n, m;
        cin >> n >> m;
        for(int i = 0; i < n; ++i){
            visited[i] = 0;
            deg[i] = 0;
            selected[i] = 0;
            e[i].clear();
        }
        for(int i = 0; i < m; ++i){
         int ex, ey;cin >> ex>>ey;
         e[ex-1].push_back(ey-1);
         e[ey-1].push_back(ex-1);
         ++deg[ex-1]; ++deg[ey-1];
        }
        if(!connectivity(n)){
            cout << "NO" <<endl;
            continue;
        }
        priority_queue<pii> pq;
        for(int i = 0; i < n; ++i){
            pq.push(mp(-deg[i],i));
        }
        bool flag = true;

        while(!pq.empty()){
            auto x = pq.top(); pq.pop();
            if(visited[x.Y] == true){
                continue;
            }
            selected[x.Y] = 1;
            visited[x.Y] = true;
            for(int i = 0; i < e[x.Y].size(); ++i){
                visited[e[x.Y][i]] = 1;
                for(int j = 0; j < e[e[x.Y][i]].size(); ++j){
                    int u = e[e[x.Y][i]][j];
                    if(visited[u]) continue;
                    --deg[u];
                    pq.push(mp(-deg[u],u));
                }
            }
        }
        int cnt = 0;
        for(int i = 0; i < n; ++i){
            if(selected[i] == 0) continue;
            ++cnt;
            for(int j = 0; j < e[i].size(); ++ j){
                if(selected[e[i][j]] == true){
                    flag = false;
                }
            }
        }
        if(flag){
            cout << "YES" << endl;
            cout << cnt <<endl;
            for(int i = 0; i < n; ++i){
                if(selected[i] == 1){
                    cout << i+1 << " ";
                }
            }
            cout << endl;
        }else{
            cout << "NO" <<endl;
        }
    }
    return 0;
}