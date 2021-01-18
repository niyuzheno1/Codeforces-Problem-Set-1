#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <algorithm>
using namespace std;

int main()
{
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    int t;
    cin >> t;
    for(int jj = 0; jj < t; ++jj){
        int n;
        cin >> n;
        vector<pair<int,int>> a;
        vector<int> ou;
        for(int i = 0; i < n; ++i){
            int x;
            cin >> x;
            a.push_back(make_pair(x,i));
            ou.push_back(0);
        }
        sort(a.begin(),a.end());
        int back = n-1;
        for(int i = 0; i < back; ++i){
            int cnt = 0;
            while(i < back && cnt < a[i].first){
                cout << a[back].second+1 << " ";
                ou[back] = 1;
                --back;
                ++cnt;
            }
            ou[i] = 1;
            cout << a[i].second+1 << " ";
        }
        for(int i = ou.size()-1 ; i >= 0;--i){
            if(ou[i] == 0)
                cout << i+1  << " ";
        }
        cout <<endl;
    }
    return 0;
}