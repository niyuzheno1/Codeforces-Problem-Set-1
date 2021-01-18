#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <queue>
#include <algorithm>
#include <windows.h>

using namespace std;

TCHAR* ExePath() {
    TCHAR buffer[MAX_PATH] = { 0 };
    GetModuleFileName( NULL, buffer, MAX_PATH );
    return buffer;
}
int main()
{
    #ifndef ONLINE_JUDGE
        freopen("input.txt","r",stdin);
        freopen("output.txt","w",stdout);
    #endif
    int t;
    TCHAR* exe = ExePath();
    
    cin >> t;
    while(t--){
        priority_queue<pair<long long,int>> pq;
        int n ;
        cin >> n;
        vector<pair<long long,long long>> a(n);
        for(int i = 0; i < n ;++i){
            cin >> a[i].second;
            a[i].second = -a[i].second;
        }
        for(int i = 0; i < n ;++i){
            cin >> a[i].first;
            a[i].first = -a[i].first;
        }
        sort(a.begin(),a.end());
        for(int i = 0; i < n ;++i){ 
            a[i].second = -a[i].second;
            a[i].first = -a[i].first;
        
        }
        for(int i = 0; i < n ;++i)
            pq.push(make_pair(a[i].second,i));
        long long ans = pq.top().first;
        long long cur = 0;
        for(int i =0;i < n; ++i)
        {
            cur += a[i].first;
            while(!pq.empty() && pq.top().second <= i ){
                pq.pop();
            }
            if(!pq.empty())
                ans = min(ans,  max(cur, pq.top().first));
            else
                ans = min(ans,  cur);
        }
        cout << ans<<endl;
    }
    return 0;
}