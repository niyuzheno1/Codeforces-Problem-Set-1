#include <iostream>
#include <vector>
#include <string>
#include <map>

using namespace std;
#define MAXN 110
int a[MAXN][MAXN];
int outputs[5*MAXN * MAXN][6];
const int dx[] = {1,-1,0,0};
const int dy[] = {0,0,1,-1};

void output(){
    cout << endl;
    for(int i = 1; i <= 2; ++i){
        for(int j = 1; j <=2 ;++j)
            cout << a[i][j] << " ";
        cout << endl;
    }

}

int ans = 0;

bool within(int u, int v, int x, int y, int nx,int ny){
    return x <= u && u <= nx && y <= v && v <= ny;
}

void add(vector<int> & z){
    for(int i = 0; i < 6; ++i)
        outputs[ans][i] = z[i];
    ++ans;

}

bool tries(int x, int y, int lx, int ly , int nx, int ny){
    vector<int> ax;
    ax.push_back(x);
    ax.push_back(y);
    a[x][y] ^= 1;
    for(int l = 0; l < 4; ++l){
        int mx = x + dx[l];
        int my = y + dy[l];
        if(within(mx,my, lx, ly, nx, ny)){
            ax.push_back(mx);
            ax.push_back(my);
            a[mx][my] ^= 1;
        }
    }
    add(ax);
    bool flag = true;
    for(int i = lx; i <= nx; ++ i)
        for(int j = ly; j <= ny; ++ j)
        {
            if(a[i][j] == 1){
                flag = false;
            }
        }
    return flag;
}

bool check(int lx, int ly ,int nx, int ny){
    bool flag = true;
    for(int i = lx; i <= nx; ++ i)
        for(int j = ly; j <= ny; ++ j)
        {
            if(a[i][j] == 1){
                flag = false;
            }
        }
    return flag;
}


int main()
{
    #ifndef ONLINE_JUDGE
        freopen("input.txt","r",stdin);
        freopen("output.txt","w",stdout);
    #endif
    // for(int k = 0; k < 3; ++k){
    //     for(int i = 1; i <= 2; ++i)
    //         for(int j = 1; j <= 2; ++j){            
    //             a[i][j] ^= 1;
    //             for(int l = 0; l < 4; ++l){
    //                 a[i+dx[l]][j+dy[l]] ^= 1;
    //             }
    //             output();
    //         }
    // }
    int tcases;
    cin >> tcases;
    for(int jj = 0 ; jj < tcases; ++jj){
    int n, m;
    cin >> n >> m;
    ans = 0;
    for (int i = 0; i < n; ++i){
            string s;
            cin >> s;
            for(int j = 0; j < m ; ++ j){
                if(s[j] == '1'){
                   
                    a[i][j] = 1;
                }else{
                    a[i][j]  = 0;
                }
                
            }
        }
    for(int i = 0; i < n - 1; i += 2)
        for(int j = 0; j < m -1 ; j += 2){
            bool flag = check(i,j, i+1, j+1);
            for(int times = 0; times < 3 && !flag; ++ times)
                for(int u = 0; u < 2 && !flag; ++u)
                    for(int v = 0; v < 2 && !flag; ++ v)
                        if( a[i+u][j+v] && tries(i+u,j+v, i,j, i+1,j+1))
                        {
                            flag = true;
                        }
        }
    for(int i = 0; i < n-1; ++i)
        for(int j = m-2; j < m ; j += 2){
            bool flag = check(i,j, i+1, j+1);
            for(int times = 0; times < 3 && !flag; ++ times)
                for(int u = 0; u < 2 && !flag; ++u)
                    for(int v = 0; v < 2 && !flag; ++ v)
                        if( a[i+u][j+v] && tries(i+u,j+v, i,j, i+1,j+1))
                        {
                            flag = true;
                        }
        }
    for(int i = n-2; i < n; i+=2)
        for(int j = 0; j < m-1 ; ++j){
            bool flag = check(i,j, i+1, j+1);
            for(int times = 0; times < 3 && !flag; ++ times)
                for(int u = 0; u < 2 && !flag; ++u)
                    for(int v = 0; v < 2 && !flag; ++ v)
                        if( a[i+u][j+v] && tries(i+u,j+v, i,j, i+1,j+1))
                        {
                            flag = true;
                        }
        }
    cout << ans <<endl;
        for(int i = 0; i < ans; ++i){
            for(int j = 0; j < 6; ++j)
                cout << outputs[i][j] +1<< " ";
            cout <<endl;
        }
    }
    
    return 0;
}