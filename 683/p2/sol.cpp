#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;


int main()
{
    #ifndef ONLINE_JUDGE
        freopen("input.txt","r",stdin);
        freopen("output.txt","w",stdout);
    #endif

    int cases; cin >> cases;
    for(int jj = 0; jj < cases; ++jj){
        int n,m; cin >> n >> m;
        vector<int> s;
        int signs = 0;
        for(int i = 0; i < n; ++i){
            for(int j = 0; j < m; ++j){
                int x;
                cin >> x;
                if(x < 0){
                    ++signs;
                    x = -x;
                }
                s.push_back(x);
            }
        }
        sort(s.begin(),s.end());
        int ret = 0;
        for(int i = 0; i < s.size(); ++i)
            ret += s[i];
        if(signs % 2 == 1){
            ret -= 2*s[0];
        }
        cout << ret <<endl;
    }
    return 0;
}