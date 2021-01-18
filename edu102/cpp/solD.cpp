#include <iostream>
#include <vector>
#include <string>
#include <cstring>
using namespace std;
int n, m;
#define MAXN 200010
int a[MAXN];
int minl[MAXN], minr[MAXN], maxl[MAXN], maxr[MAXN];


int main()
{
    #ifndef ONLINE_JUDGE
        freopen("input.txt","r",stdin);
        freopen("output.txt","w",stdout);
    #endif
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int tcases;
    cin >> tcases;
    while(tcases--){
        memset(a,0,sizeof(a));
        memset(minl,0,sizeof(minl));
        memset(minr,0,sizeof(minr));
        memset(maxr,0,sizeof(maxr));
        memset(maxl,0,sizeof(maxl));
        int n,m;
        cin >> n >> m;
        string s;
        cin >> s;
        s = " " + s;
        for(int i = 1; i <= n; ++i){
            if(s[i] == '+')
                a[i] = a[i-1] + 1;
            else{
                a[i] = a[i-1]-1;
            }
        }
        for(int i = 1; i <= n; ++i){
            minl[i] = min(minl[i-1], a[i]);
            maxl[i] = max(maxl[i-1], a[i]);
        }
        maxr[n] = minr[n] = a[n];
        for(int i = n-1; i >= 0; --i){
            minr[i] = min(minr[i+1], a[i]);
            maxr[i] = max(maxr[i+1], a[i]);
        }
        for(int i = 0; i < m; ++i){
            int l, r; cin >> l >> r;
            int shifts =  a[l-1]-a[r];
            if(l == 1 && r == n){
                cout << 1 << endl;
            }else if(l == 1){
                cout << max(0,maxr[r+1]+shifts)- min(0,minr[r+1]+shifts) + 1 << endl;
            }else if(r == n){
             cout << maxl[l-1] - minl[l-1] + 1 << endl;
            }
            else{
                cout << max(maxl[l-1], shifts+maxr[r+1])- min(minl[l-1], shifts+minr[r+1]) + 1 << endl;
            }
            
        }
    }
    return 0;
}