#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

int main()
{
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    int t;
    cin >> t;
    for(int i = 0; i < t; ++i){
        vector<long long> a;
        int n;
        cin >> n;
        int m = n;
        for(int j = 0; j < n; ++j){
            long long x;
            cin >> x;
            a.push_back(x);
        }
        sort(a.begin(),a.end());
        long long ans = 0;
        for(int j = 0; j < m; ++j){
           ans = max(ans, a[j] * (m-j));
        }
        cout << ans <<endl;

    }
    return 0;
}