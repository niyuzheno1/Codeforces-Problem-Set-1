#include <iostream>
#include <vector>
#include <string>

using namespace std;
 
#define sz(x) (int)x.size()
#define pb push_back
#define mp make_pair
#define ll long long 
#define mod 1000000007
#define endl "\n"
typedef vector<int> vi; 
typedef pair<int, int> pi; 
 
int fast(){
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    return 0;
}
int main(){
	fast();
	ll t;
	cin>>t;
	// t = 1;
	while(t--){
		int n;
		cin>>n;
		vector<int> lol;
		// lol.pb(4);
		// int k = 0;
		for(int i = 0; i < n; i ++){
			lol.pb(2*i+1);
			// k++;
		}
		// cout<<k<<endl;
		for(int i = 0; i < lol.size() ; i++){
			for (int j = i+1; j < lol.size(); j ++){
				if(lol[j] % lol[i] == 0){
					lol[i] *= 2;
				}
			}
		}
		for(int i = 0; i < n; i ++){
			lol[i] = 2 * lol[i];
		}
		lol[0] =  8;
		// for(int i = 6; i < 4*n+1; i+=2){
		// 	std::vector<int>::iterator it;
		// 	it = std::find (lol.begin(), lol.end(), i); 
 
		// 	if(it == lol.end()){
		// 		lol[0] = i;
		// 	}
		// }
		if(n == 1)lol[0] = 1;
		for(int i = 0; i < n; i ++){
			cout<<lol[i]<<" ";
		}
 
		cout<<endl;
	}
}
 