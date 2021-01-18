#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

#define MAXN 200010
#define MAXB 32
typedef vector<int> vi;
typedef vector<vi> vii;
typedef pair<int,int> pii;
typedef pair<pii,int> pti;
#define X first
#define Y second
#define geti(x) x.second
#define mp make_pair
 
// void preprocess(vi arr, vii lookup, int n)
// {
//     for (int i = 0; i < n; i++)
//         lookup[i][0] = i;
 
//     for (int j = 1; (1 << j) <= n; j++) 
//     {
//         for (int i = 0; (i + (1 << j) - 1) < n; i++) 
//         {
//             if (arr[lookup[i][j - 1]]
//                 < arr[lookup[i + (1 << (j - 1))][j - 1]])
//                 lookup[i][j] = lookup[i][j - 1];
//             else
//                 lookup[i][j]
//                     = lookup[i + (1 << (j - 1))][j - 1];
//         }
//     }
// }
 
// int query(vi arr,  vii lookup, int L, int R)
// {
//     int j = (int)log2(R - L + 1); 
//     if (arr[lookup[L][j]]
//         <= arr[lookup[R - (1 << j) + 1][j]])
//         return (lookup[L][j]);
//     else
//         return (lookup[R - (1 << j) + 1][j]);
// }
 
// preprocess(arr, lookup n);
 
int main()
{
    #ifndef ONLINE_JUDGE
        freopen("input.txt","r",stdin);
        freopen("output.txt","w",stdout);
    #endif
    int tcases;
    cin >> tcases;
    while(tcases--){
        int n;
        cin >> n;
        vii f(n);
        for(int i = 0; i < n; ++i)
            f[i] = vi(32);
        vector<pii> a(n);
        vector<pti> b(n);
        vector<pti> c(n);
        vi ans(n,-1);
        for(int i = 0; i < n; ++i)
        {
            int w,h;cin >> w >> h;
            a[i] = mp(w,h);
            b[i] = mp(mp(h,w),i);
            c[i] = mp(mp(w,h),i);
        }
        sort( b.begin( ), b.end( ));
        sort( c.begin( ), c.end( ));
        // vector<int> h(n);
        // for(int i = 0; i < n; ++i)
        //     h[i] = c[i].X.Y;
        // preprocess(h, f, n);
        int wmin = INT_MAX, idx = 0;
        int widx = -1;
        for(int i = 0; i < n; ++i){
             while(idx < n && b[idx].X.X < b[i].X.X){
                 if(wmin > b[idx].X.Y){
                     wmin = b[idx].X.Y;
                     widx = geti(b[idx]);
                 }
                 ++idx;
             }
            if(wmin < b[i].X.Y){
                 ans[geti(b[i])] = widx+1; 
            }
        }
        idx = 0;
        int hmin = INT_MAX, hidx = -1;
        for(int i = 0; i < n; ++i){
            while(idx < n && c[idx].X.X < b[i].X.X){
                if (hmin > c[idx].X.Y){
                    hmin = c[idx].X.Y;
                    hidx = geti(c[idx]);
                }
                ++idx;
            }
            if(hmin < b[i].X.Y){
                 ans[geti(b[i])] = hidx+1; 
            }
        }
        for(int i = 0; i < n; ++i){
            cout << ans[i] << " ";
        }
        cout <<endl;

    }    
    return 0;
}