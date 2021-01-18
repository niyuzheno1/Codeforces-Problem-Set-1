#include <iostream>
#include <vector>
#include <string>
#include <map>

using namespace std;
#define MAXN 100010
typedef long long ll;
ll pre[3][MAXN];
ll pos[3][MAXN];
ll cs[MAXN];
ll n;
ll compute(ll x, ll y, ll z){
	ll w = z^1;
	ll pairs = 0;
	for(ll i = 1; i <= n; ++i)
		if(cs[i] == 2){
			 pairs +=  pre[w][i-1] * y + pos[w][i+1] * x; 
		}
	ll ans = pairs;
    ll prev = 0;
	for(ll i = 1; i <= n; ++i){
		if(cs[i] == 2){
			 pairs -=  pre[w][i-1] * y + pos[w][i+1] * x;
             pairs -= prev;
			 pairs +=  pre[z][i-1] * x + (pos[z][i+1] + pos[2][i+1]) * y;
             prev += y;
		}
		ans = min(pairs, ans);
	}
	return ans; 	
}

int main()
{
    #ifndef ONLINE_JUDGE
        freopen("input.txt","r",stdin);
        freopen("output.txt","w",stdout);
    #endif
    map<char, ll> fa;
	fa['0'] = 0;
	fa['1'] = 1;
	fa['?'] = 2;
	string s; cin >> s;
	ll x, y; cin >> x >> y;
	n = s.length();
	for(ll i = 0; i < n ; ++ i)
		cs[i+1] = fa[s[i]];
	for(ll i = 1; i <= n ; ++ i){
		for(ll j = 0; j <= 2; ++j)
			pre[j][i] = pre[j][i-1];
		++pre[cs[i]][i]; 
	}
	for(ll i = n; i >= 1 ; -- i){
		for(ll j = 0; j <= 2; ++j)
			pos[j][i] = pos[j][i+1];
		++pos[cs[i]][i]; 
	}
	ll invariance = 0;
	for(ll i = 1; i <= n; ++i){
		if(cs[i] == 0 )
			invariance += pre[1][i-1] * y + pos[1][i+1] * x; 
	}
	ll r1 = compute(x,y,0);
	ll r2 = compute(y,x,1);
	cout << min (r1, r2) + invariance <<endl;


    return 0;
}