#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include <algorithm>

using namespace std;
typedef long long ll;
 
using namespace std;
#define int long long
 
const int INF = 0x3f3f3f3f;
const int N = 2e5+10;
 
int a[N];

int func(int i){
    if(i != 1)
        return 1;
    else
    {
        return 1000000000;
    }
    
}
 
signed main() {
  #ifndef ONLINE_JUDGE
        freopen("input.txt","r",stdin);
        freopen("output.txt","w",stdout);
    #endif
	int T;
	T = 1;
	while(T--){
		int n;
		n = 100000;
		int sum = 0;
		for(int i=1;i<=n;i++) a[i] = func(i),sum+=a[i];
		sort(a+1,a+1+n);
		int ans = a[n]*(n-1)-sum;
		if(ans<0){
			int ch = abs(ans);
			int cnt = ch/(n-1);
			if(cnt*(n-1)<ch) cnt++;
			ans = (a[n]+cnt)*(n-1)-sum;
		}
		cout<<ans<<endl;
		
	}
 
 
	return 0;
}
 