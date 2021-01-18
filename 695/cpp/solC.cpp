#include <iostream>
#include <vector>
#include <string>

using namespace std;
#define MAXN 300010
typedef long long ll;
ll a[3][MAXN];
ll s[MAXN];
ll mins[3];
ll min_id[3];
ll maxs[3];
ll max_id[3];
ll n[3];
int main()
{
    #ifndef ONLINE_JUDGE
        freopen("input.txt","r",stdin);
        freopen("output.txt","w",stdout);
    #endif
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    
    cin >> n[0] >> n[1] >> n[2];
    for(int i = 0; i < n[0]; ++i) cin >> a[0][i];
    for(int i = 0; i < n[1]; ++i) cin >> a[1][i];
    for(int i = 0; i < n[2]; ++i) cin >> a[2][i];
    for(int i = 0; i < 3; ++ i){
        for(int j = 0; j < n[i]; ++ j){
            if(a[i][min_id[i]] > a[i][j])
                min_id[i] =j;
            if(a[i][max_id[i]] < a[i][j])
                max_id[i] =j;
        }
    }
    int best = 0;
    for(int i = 0; i < 3; ++i){
        if(a[best][min_id[best]] > a[i][min_id[i]])
            best = i;
    }
    int best1 = (best+1)%3, best2 = (best+1)%3;
    for(int i = 0; i < 3; ++i){
        if(i == best) continue;
        if(abs(a[i][max_id[i]]-a[best][min_id[best]]) > abs(a[best][min_id[best]]-a[best1][max_id[best1]])){
            best1 = i;
        }
        if(abs(a[i][min_id[i]]-a[best][max_id[best]]) > abs(a[best][max_id[best]]-a[best2][min_id[best2]])){
            best2 = i;
        }
    }
    a[best][min_id[best]] = abs(a[best1][max_id[best1]] - a[best][min_id[best]]);
    a[best1][max_id[best1]] = 0;
    if(min_id[best] != max_id[best]){
        if(best1 != best2 || min_id[best1] != max_id[best2]){ 
            a[best][max_id[best]] = abs(a[best2][min_id[best2]] - a[best][max_id[best]]);
            a[best2][min_id[best2]] = 0;
        }else{
            int dx = 0;
            for(int i = 0; i < 3; ++i)
            {
                if(best != i && best1 != i){
                    dx = i;
                    break;
                }
            }
            a[best][max_id[best]] = abs(a[best][max_id[best]]-a[dx][min_id[dx]]);
            a[dx][min_id[dx]] = 0;
        }
    }
    ll sum = 0;
    for(int i = 0; i < 3; ++ i){
        for(int j = 0; j < n[i]; ++ j){
            sum += a[i][j];
        }
    }
    cout << sum <<endl;
    return 0;
}