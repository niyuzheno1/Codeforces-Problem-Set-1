#include <iostream>
#include <vector>
#include <string>
#include <iomanip>
using namespace std;

#define MAXN 100010
bool sorted[MAXN];
int a[MAXN];
int premax[MAXN];
bool notsorted[MAXN];

int main()
{
    #ifndef ONLINE_JUDGE
        freopen("input.txt","r",stdin);
        freopen("output.txt","w",stdout);
    #endif
    cout << setprecision(6) << fixed; 
    int tcases; cin >> tcases;
    for(int jj = 0; jj < tcases; ++jj){
        int n, m; cin >> n >> m;
        sorted[n] = true;
        a[n] = n + 10;
        for(int i = 0; i < n; ++ i) cin >> a[i];
        premax[0] = a[0];
        for(int i = 1; i <= n; ++ i) premax[i] = max(premax[i-1], a[i]);
        for(int i = n-1; i >= 0; -- i) 
            if(a[i] < a[i + 1])
                sorted[i] = sorted[i+1];
            else
                sorted[i] = false;
        notsorted[0] = sorted[0];
        for(int i = 1; i <= n; ++ i) notsorted[i] = notsorted[i-1] && sorted[i]; 
        double nottaken = 1.0;
        double overall = 0.0;
        for(int i = 0; i < m; ++ i){
            int r; double p;
            cin >> r >> p;
            --r;
            if(!notsorted[r])
                if(premax[r] < a[r+1]) //1 
                {
                    if(sorted[r+1]){
                        overall += p * nottaken;
                        nottaken *= (1-p);
                    }
                } 
        }
        if(sorted[0] == 1)
            cout << 1.0 <<endl;
        else
            cout << overall << endl;
    }
    return 0;
}