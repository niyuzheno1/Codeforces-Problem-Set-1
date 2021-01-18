#include <iostream>
#include <vector>
#include <string>

using namespace std;
#define  MAXN 300010 
int a[MAXN];
int init[MAXN];
int n;
int y[3];
#define and &&
#define or ||
int getval(int x){
    int ans = 0;
    if (x <= 0 or x >= n-1)
        return 0;
    if ( a[x] > a[x-1] and a[x] > a[x+1])
        return 1;
    if(a[x] < a[x-1] and a[x] < a[x+1])
        return 1;
    return 0;

}
int diff(int x){
    int ret = 0;
    if(x > 0)
        ret += y[0]-init[x-1];
    if(x < n-1)
        ret += y[2]-init[x+1];
    return y[1]-init[x] + ret;
}
int main()
{
    #ifndef ONLINE_JUDGE
        freopen("input.txt","r",stdin);
        freopen("output.txt","w",stdout);
    #endif
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int tcases; cin >> tcases;
    for(int jj = 0; jj < tcases; ++ jj){
        cin >> n;
        for(int i = 0; i < n; ++i) cin >> a[i];
        int ans = 0;
        for(int i = 0; i < n; ++i){
            init[i] = getval(i);            
            ans += init[i];  
        }
        int s = ans;
        for(int i = 0; i < n; ++i){
            int lefx = i == 0  ? a[i] : a[i-1];
            int rigx = i == n-1  ? a[i]  : a[i+1];
            int r = a[i];
            a[i] = lefx;
            y[0] = (getval(i-1));
            y[1] = (getval(i));
            y[2] = (getval(i+1));
            s = min(s, ans+diff(i));
            a[i] = rigx;
            y[0] = (getval(i-1));
            y[1] = (getval(i));
            y[2] = (getval(i+1));
            s = min(s, ans+diff(i));
            a[i] = r;
        }
        cout << s <<endl;
    }
    return 0;
}