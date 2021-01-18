#include <iostream>
#include <vector>
#include <string>

using namespace std;

#define MAXN 100010

int sum[MAXN];
int last[MAXN];

int main()
{
    #ifndef ONLINE_JUDGE
        freopen("input.txt","r",stdin);
        freopen("output.txt","w",stdout);
    #endif
    int tcases;
    cin >> tcases;
    for(int jj = 0; jj < tcases; ++ jj){
        int n, p, k;
        cin >> n >> p >> k;
        int x,y;
        string a;
        cin >> a;
        cin>>x>>y;
        for(int i = 0; i <= n; ++ i){
            sum[i] = 0;
            last[i] = 0;
        }
        for(int i = p; i < p + k; ++i){
            int pre = -1;
            int it = i;
            while(it <= n){
                if(a[it-1] == '0'){
                    sum[it] = x;
                }
                if(pre != -1)
                    sum[it] += sum[pre];
                pre = it;
                it += k;
            }
            
            it -= k;
            while(it > 0){
                last[it] = pre;
                it -= k;
            }
        }
        int ans = sum[last[p]];
        for(int i = 1; i <= n-p; ++i){
            int diff = 0;
            if(p+i-k > 0)
                diff = sum[p+i-k];
            int tmpans = (sum[last[p+i]]-diff) + y * i;
            ans = min(ans, tmpans);
        }
        cout << ans <<endl;
    }
    return 0;
}