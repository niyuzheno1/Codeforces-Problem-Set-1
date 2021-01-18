#include <iostream>
#include <vector>
#include <string>
#include <queue>

using namespace std;

typedef long long ll;

int main()
{
    #ifndef ONLINE_JUDGE
        freopen("input.txt","r",stdin);
        freopen("output.txt","w",stdout);
    #endif
    int tcases;
    cin >> tcases;
    for(int jj = 0; jj < tcases; ++ jj){
        int n;
        cin >> n;
        vector<ll> a(n);
        ll maxx = 0;
        ll maxi = 0;
        ll secondmax = 0;
        for(int i = 0; i < n; ++i)
        {
             cin >> a[i];
             if(maxx <  a[i]){
                secondmax = maxx;
                maxx = a[i];
                maxi = i;
             }else if(a[i] >= secondmax){
                 secondmax = a[i];
             }
        }
        ll whatactuallyweneed = 0;
        ll sumx = 0;
        for(int i = 0; i < n; ++i){
            whatactuallyweneed += ( maxx- a[i]);
            if(maxi != i)
                sumx += (secondmax - a[i]);
        }
        ll ans = 0;
        for(int i = 0; i < n; ++i)
        {
            if(i == maxi)
                continue;
            ll whatweneed = whatactuallyweneed - ( maxx -a[i]);
            ll tmp = a[i];
            ll tmpans = 0;
            if(whatweneed >= tmp){
                tmpans = whatweneed - tmp;
            }else{
                tmp = tmp - whatweneed;
                if (tmp % (n-1) != 0)
                    tmpans += (n-1)-(tmp % (n-1));
            }
            ans = max(ans, tmpans);
        }
        ll tmpans =0 ;
        ll tmp = a[maxi];
        if(sumx >= tmp){
            tmpans = sumx - tmp;
        }else{
            tmp = tmp - sumx;
            if(tmp % (n-1) != 0)
                tmpans = (n-1)-(tmp % (n-1));
        }
        ans = max(ans, tmpans);
        
        cout << ans <<endl;

    }
    return 0;
}