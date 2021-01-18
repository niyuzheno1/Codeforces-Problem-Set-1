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
        freopen("input.txt","w",stdout);
    #endif
    cout << 1 <<endl;
    cout << 5 << " " << 5 <<endl;
    for(int i = 0 ; i < 5; ++i){
        for(int j = 0; j < 5; ++j)
            cout << 1 << " ";
        cout << endl;
    }

    return 0;
}