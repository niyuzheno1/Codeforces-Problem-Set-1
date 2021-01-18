#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main()
{
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    int t;
    cin >> t;
    for(int i = 0; i< t; ++i){
        int n,k;
        vector<int> a;
        cin >> n >> k;
        for(int j = 0; j < n; ++j){
            int x;
            cin>>x;a.push_back(x);
            
        }
        int ans = 0;
        for(int j = 0; j < a.size(); ++j){
            int x = a.size()-j;
            int xk =  x/k;
            int u = 0;
            for(int l = 0; l < xk && j + l < a.size(); ++l){
                
                u += a[j+l];
            }
            ans = max(ans, u);
        }
        cout << ans << endl;
    }
    return 0;
}