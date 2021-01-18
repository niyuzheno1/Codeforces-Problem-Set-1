#include <iostream>
#include <vector>
#include <string>

using namespace std;
auto bsearch1 = [&](int xh){
            int l = 0, r = n-1;
            while( r - l > 1){
                int mid = (l+r)>>1;
                if(b[mid].X.X < xh){
                    l = mid;
                }else{
                    r = mid-1;
                }
            }
            if(b[r].X.X < xh) return r;
            return l;
        };
auto bsearch = [&](int xh){
            int l = 0, r = n-1;
            while( r - l > 1){
                int mid = (l+r)>>1;
                if(c[mid].X.Y < xh){
                    l = mid;
                }else{
                    r = mid-1;
                }
            }
            if(c[r].X.Y < xh) return r;
            return l;
        };
int main()
{
    #ifndef ONLINE_JUDGE
        freopen("input.txt","r",stdin);
        freopen("output.txt","w",stdout);
    #endif
    return 0;
}