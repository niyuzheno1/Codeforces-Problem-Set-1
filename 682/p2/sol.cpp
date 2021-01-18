#include <iostream>
#include <vector>
#include <string>
#include <set>
using namespace std;
//O(nlogn) algorithm by checking if an element exists
int main()
{
    #ifndef ONLINE_JUDGE
        freopen("input.txt","r",stdin);
        freopen("output.txt","w",stdout);
    #endif
    int t; cin >> t;
    for(int jj = 0; jj < t; ++jj){
        int n; cin >> n;
        set<int> s;
        int flag = false;
        for(int i = 0; i < n; ++i){
            int x;
            cin >> x;
            if(s.find(x) != s.end()){
                flag = true;
            }
            s.insert(x);
        }
        if(flag == false)
            cout << "NO" <<endl;
        else
        {
            cout << "YES" <<endl;
        }
        
    }
    return 0;
}