#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include <map>
#include <set>

using namespace std;

typedef pair<int,int> pii;
typedef pair<pii,pii> ps;
const int dx[] = {1,0,-1,0};
const int dy[] = {0,1,0,-1};
#define mp make_pair
set<pii> f[21];
#define x first
#define y second
void bfs(){
    queue<ps> q;
    q.push(mp(mp(0,0), mp(0,0)));
    while(!q.empty()){
        ps u = q.front(); q.pop();
        f[u.y.x].insert(u.x);
        if(u.y.x > 10) break;
        for(int i = 0; i < 4; ++i){
            int nx = u.x.x + dx[i];
            int ny = u.x.y + dy[i];
            int nd = u.y.x + 1;
            int st = i;
            if((st+u.y.y) % 2 != 0 || u.y.x == 0)
                q.push(mp(mp(nx,ny), mp (nd,st)));
            
        }
    }
}

int main()
{
    #ifndef ONLINE_JUDGE
        freopen("input.txt","r",stdin);
        freopen("output.txt","w",stdout);
    #endif
    bfs();
    for(int i = 0; i <= 10; ++i)
        cout << f[i].size() <<endl;
    return 0;
}