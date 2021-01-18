#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include <algorithm>
#include <map>
using namespace std;
typedef pair<long long, int> pii;


long long upper(long long x){
    if(x % 2 == 1)
        return (x+1)/2;
    return x/2;
}

int main()
{
    #ifndef ONLINE_JUDGE
        freopen("input.txt","r",stdin);
        freopen("output.txt","w",stdout);
    #endif
    int testcases; cin >> testcases;
    for(int jj = 0; jj < testcases; ++jj){
        priority_queue<pii> g;
        int n;
        long long w;
        cin >> n >> w;
        vector<pii> a;
        for(int i = 0; i < n; ++i){
            long long x; cin >> x;
            a.push_back(make_pair(x,i));
        }
        sort(a.begin(), a.end());
        long long y = 0;
        vector<int> output;
        for(int i = 0; i < n; ++i){
            y += a[i].first;
            if(y > w){
                while(!g.empty() && y > w){
                    y -= g.top().first;
                    g.pop();
                }
            }
            if(upper(w) <= y && y <= w){
                output.push_back(a[i].second);
                while(!g.empty()){
                    output.push_back(g.top().second);
                    g.pop();
                }
                break;
            }
            g.push(make_pair(a[i].first,a[i].second));
        }
        int m = output.size();
        if(m == 0)
        {
            cout << "-1" <<endl;
        }else{
            cout << m << endl; 
            for(int i = 0; i < m; ++i){
                cout << output[i]+1 << " ";
            }
            cout << endl;
        }
    }
    return 0;
}