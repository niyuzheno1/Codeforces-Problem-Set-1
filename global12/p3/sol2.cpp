


#include <iostream>
#include <vector>
#include <string>

using namespace std;
#define MAXN 300
int n, m = 9;
char a[MAXN][MAXN];

const int stpx[] = {0, 0, 0, -1, -1, -1, -2,-2,-2};
const int stpy[] = {0, -1, -2, 0, -1, -2, 0, -1, -2};


bool within(int x, int y){
    return 0 <= x && 0 <= y && x < n && y < n;
}

int res(int x, int y){
    return (a[x][y] == 'X') ? 1 : 0;
}

bool intersection(int x, int y, bool mid){
    bool ret = false;
    for(int k = 0; k <= m; ++ k){
        int u = stpx[k];
        int v = stpy[k];
        int cnt = 0;
        for(int j = 0; j < 3; ++ j)
            if(within(x+u+j, y))
                cnt += res(x+u+j, y);
        
        for(int j = 0; j < 3; ++j)
            if(within(x, y+v+j) && y+v+j != y)
                cnt += res(x, y + v + j);
        if(cnt == 5 && mid == false)
            return true;
        else if(cnt == 5 && mid == true && u == -1 &&v == -1)
            return true;
    }
    return false;
}
bool threes(int x, int y){
    for(int k = 0; k <= m; ++ k){
         int u = stpx[k];
        int v = stpy[k];
        int cnt = 0;
        for(int j = 0; j < 3; ++ j)
            if(within(x+u+j, y))
                cnt += res(x+u+j, y);
        if(cnt == 3 && u == -1){
            return true;
        }
        cnt = 0;
        for(int j = 0; j < 3; ++j)
            if(within(x, y+v+j))
                cnt += res(x, y + v + j);
        if(cnt == 3 && v == -1){
            return true;
        }
    }
    return false;
}

int main()
{
    #ifndef ONLINE_JUDGE
        freopen("input.txt","r",stdin);
        freopen("output.txt","w",stdout);
    #endif
    int tcases; cin >> tcases;
    for(int jj = 0; jj < tcases; ++jj){
        cin >> n;
        for(int i = 0; i < n; ++i){
            cin>>a[i];
        }
        
        for(int i = 0; i < n; ++i)
            for(int j = 0; j < n; ++j)
                if(intersection(i,j, true))
                {
                    a[i][j] = 'O';
                }
       
        
        for(int i = 0; i < n; ++i)
            for(int j = 0; j < n; ++j)
                if(intersection(i,j, false))
                {
                    a[i][j] = 'O';
                }
        
        for(int i = 0; i < n; ++i){
            for(int j = 0; j < n; ++j)
                cout<<a[i][j];
            cout <<endl;
        } 
        for(int i = n-1; i >= 0; --i)
            for(int j = n-1; j >= 0; --j)
                if(threes(i,j)){
                    a[i][j] = 'O';
                }
       

    }
    return 0;
}