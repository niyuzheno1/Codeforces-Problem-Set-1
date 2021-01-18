#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include <map>
using namespace std;

#define MAXN 110

int a[MAXN][MAXN];
int b[MAXN][MAXN];
const int dx[] = {-1,1,0,0};
const int dy[] = {0,0,-1,1};

bool within(int x,int y, int n, int m){
    return 0 <= x && x < n && 0<=y && y < m;
}
typedef pair<int,int> pii;
void bfs(int x, int y, int n, int m){
    queue<pii> qp;
    qp.push(make_pair(x,y));
    if(b[x][y] > 0){
        return;
    }
    b[x][y] = 0;
    while(!qp.empty()){
        pii fr = qp.front(); qp.pop();
        int i = fr.first, j = fr.second;
        int xx = a[i][j];
        bool flag = false;
        for(int k = 0; k < 4; ++k)
            if(within(i+dx[k], j + dy[k], n, m)){
                        int yy = a[i+dx[k]][j + dy[k]];      
                        if(yy == xx){
                            flag = true;
                        }
                    }
        if(flag){
            if(b[i][j] > 0){
                ++a[i][j];
            }
        }
         xx = a[i][j];
        for(int k = 0; k < 4; ++k)
            if(within(i+dx[k], j + dy[k], n, m)){
                        int yy = a[i+dx[k]][j + dy[k]];      
                        if(yy == xx){
                           b[i+dx[k]][j + dy[k]] = b[i][j] + 1;
                           qp.push(make_pair(i+dx[k],j + dy[k]));
                        }
                    }
         
    }
}


int main()
{
    #ifndef ONLINE_JUDGE
        freopen("input.txt","r",stdin);
        freopen("output.txt","w",stdout);
    #endif
    int t; cin >> t;
    for(int jj = 0; jj < t; ++jj){
        int n,m; cin >> n >> m;
        for(int i = 0; i <n ; ++i)
            for(int j = 0; j < m; ++j){
                cin >> a[i][j];
                b[i][j] = 0;
            }
        
        for(int cases = 0; cases < 10; ++ cases)
            for(int i = 0; i < n; ++i)
                for(int j = 0; j < m; ++j){

                    int xx = a[i][j];
                    int flag = false;
                    for(int k = 0; k < 4; ++k){
                        if(within(i+dx[k], j + dy[k], n, m)){
                            int yy = a[i+dx[k]][j + dy[k]];
                            if(yy == xx){
                                flag = true;
                            }
                        }
                    }
                    if(flag)
                    {
                        bfs(i,j,n,m);
                    }
                }
        for(int i = 0; i < n; ++i){
            for(int j = 0; j < m; ++j){
                cout << a[i][j] << " ";
            }
            cout << endl;
        }
    }

    return 0;
}