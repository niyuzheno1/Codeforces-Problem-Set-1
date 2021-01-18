#include <iostream>
#include <vector>
#include <string>

using namespace std;
#define MAXN 200010
int h[MAXN];
int a[MAXN];
int b[MAXN];
int c[MAXN];
int main()
{
    #ifndef ONLINE_JUDGE
        freopen("input.txt","r",stdin);
        freopen("output.txt","w",stdout);
    #endif
    int tcases; cin >> tcases; 
    while(tcases--){
        int n, k; 
        cin >> n >> k;
        for(int i = 0; i < n; ++i){
            cin >> h[i];
        }
        int x = h[0];
        a[0] = x;
        for(int i = 1; i < n; ++i)
            a[i] = min(a[i-1]+k-1,h[i]+k-1);
        b[n-1] = h[n-1];
        for(int i = n-2; i >=0 ; --i)
            b[i] = min(b[i+1]+k-1, h[i]+k-1);
        int pts = 0;
        for(int i = 0; i < n; ++i){
            if(a[i] >= b[i]){
                pts = i;
                break;
            }
        }
        for(int i = 0; i < n; ++i){
            if(i < pts)
                c[i] = a[i];
            else{
                c[i] = b[i];
            }
        }

        bool flag = true;
        for(int i = 0; i < n; ++i){
            if(c[i] - h[i] > k-1 || c[i] < h[i] || abs(c[i]-c[i-1]) > k-1){
                flag = false;
            }
        }
        if(flag) 
            cout << "YES" <<endl;
        else 
            cout << "NO" <<endl;
    }
    return 0;
}