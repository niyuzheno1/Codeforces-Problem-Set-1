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
    for(int jj = 0; jj < t;++jj){
        int n,k,x;
        cin>>n>>k>>x;
        vector<int> a;
        vector<pair<int,int>>b;
        for(int i = 0;i <n;++i){
            int x;
            cin >> x;
            a.push_back(x);
            b.push_back(make_pair(x,i));
        }
        sort(b.begin(),b.end());
        for(int i = 0; i < k; ++i){
            int pos = b.size()-i-1;
            a[b[pos].second] = -1;
        }
        int maxsum = 0;
        for(int i = 0; i < a.size();){
            int sum = 0;
            for(int j = 0; j < x && i  < a.size(); ){
                if(a[i] > 0){
                    sum += a[i];
                    ++j; ++i;
                }else{
                    ++i;
                }
            }
            maxsum = max(maxsum, sum);
        }
        cout << maxsum <<endl;
    }
    return 0;
}