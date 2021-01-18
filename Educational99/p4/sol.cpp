#include <iostream>
#include <vector>
#include <string>

using namespace std;
#define MAXN 510

int look[MAXN][MAXN];

int main()
{
    #ifndef ONLINE_JUDGE
        freopen("input.txt","r",stdin);
        freopen("output.txt","w",stdout);
    #endif
    int tcases = 0;
    cin >> tcases;
    for(int jj = 0; jj < tcases; ++ jj){
        int n, x; cin >> n >> x;
        vector<int> a;
        for(int i = 0; i < n; ++i){
            int y; cin >> y;
            a.push_back(y);
        }
        for(int i = 0; i < MAXN; ++i)
            look[n][i] = -1;
        for(int i = n-1; i >= 0; --i){
            for(int j = 0; j < MAXN; ++ j)
             look[i][j] = look[i+1][j];
            look[i][a[i]] = i;
        }
        int sorted = -1;
        for(int i = 0; i < n-1; ++i){
            if(a[i] > a[i+1]){
                sorted = i + 1;
                break;
            }
        }
        if(sorted == -1){
            cout << "0" << endl;
            continue;
        }
        int ind = 0;
        int ans = 0;
        while(true){
            int find = -1;
            for(int i = x+1; i < MAXN; ++i)
                if (look[ind][i] != -1){
                    find = look[ind][i];
                    break;
                }
            bool sorted2 = 1;
            for(int i = 0; i < n-1; ++i){
                if(a[i] > a[i+1])
                    sorted2 = 0;
            }
            if(find == -1 || sorted2)
                break;
            int tmp = a[find];
            a[find] =  x;
            x = tmp;
            ind = find + 1;
            ++ans;
        }
        sorted = 1;
        for(int i = 0; i < n-1; ++i){
            if(a[i] > a[i+1])
                sorted = 0;
        }       
        if(!sorted){
            cout << -1 <<endl;
        }else{
            cout << ans <<endl;
        }
    }
    return 0;
}