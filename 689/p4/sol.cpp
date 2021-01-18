#include <iostream>
#include <vector>
#include <string>
#include <cstring>
#include <algorithm>
#include <map>
using namespace std;
#define MAXN 100010
typedef long long ll;
ll a[MAXN], n;
ll sind[MAXN];
ll presum[MAXN];

int binsearch(ll x) 
{ 
    int l = 0, r = n-1;
    while (l <= r) { 
        int m = (l+r)>>1; 
        if (a[m] == x) 
            return sind[m]; 
        if (a[m] < x) 
            l = m + 1; 
        else
            r = m - 1; 
    } 
    int pos = (l+r)>>1;
    while(a[pos] > x){
        --pos;
    }
    
    while(a[pos+1] < x){
        ++pos;
    }
    return sind[pos]; 
} 


map<ll, int> mem; 
bool recurse(ll x,int lf, int rf){
    if(a[lf] == a[rf])
        return false;
    bool ret = false;
    ll md = (a[rf] + a[lf]) >> 1;
    int lind = binsearch(md);
    ll diff =  lf-1 >= 0 ? presum[lf-1] : 0;
    ll lsum = presum[lind] - diff;
    ll rsum = presum[rf] -  presum[lind];
    mem[lsum] = mem[rsum] = 1;
    if(lsum > x){
        ret = ret || recurse(x,lf, lind);
    }     
    if(rsum > x){
        ret = ret || recurse(x,lind+1,rf );
    }
    if(lsum == x){
        return true;
    }else if(rsum == x){
        return true;
    }
    return ret;
}


int main()
{
    #ifndef ONLINE_JUDGE
        freopen("input.txt","r",stdin);
        freopen("output.txt","w",stdout);
    #endif
    int tcases; cin >> tcases;
    for(int jj = 0; jj < tcases; ++ jj){
        int q;
        mem.clear();
        memset(a, 0 ,sizeof(a));
        memset(sind, 0 ,sizeof(sind));
        memset(presum, 0 ,sizeof(presum));
        cin >> n >> q;
        for(int i = 0; i < n; ++i) cin >> a[i];
        sort(a, a + n);
        presum[0] = a[0];
        for(int i = 1; i <n; ++i) presum[i] = presum[i-1] + a[i];
        ll cur = 0;
        for(int i = n-1; i >= 0 ; -- i)
            if(a[i] != cur){
                sind[i] = i;
                cur = a[i];
            }else
                sind[i] = sind[i+1];
        
        for(int i = 0; i < q; ++ i){
            bool ans = true;
            bool verified = false;
            ll x; cin >>x;
            int lf = 0, rf = n-1;
            if(mem[x] == 0)
                if(presum[n-1] != x){
                    verified = ans = recurse(x, 0, n-1);
                }
                else{
                    verified = ans = true;
                }
            else{
                if(mem[x] == 1) verified = ans = true;
                else if(mem[x] == 2) verified = ans = false;
            }
            if(verified && ans){
                mem[x] = 1;
                cout << "Yes" <<endl;
            }
            else
            {
                mem[x] = 2;
                cout << "No" <<endl;
            }
            
        }
    }
    return 0;
}