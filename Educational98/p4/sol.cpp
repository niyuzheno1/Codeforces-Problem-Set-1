#include <iostream>
#include <vector>
#include <string>

using namespace std;

int f[1000];

int main()
{
    #ifndef ONLINE_JUDGE
        freopen("input.txt","r",stdin);
        freopen("output.txt","w",stdout);
    #endif
    f[0] = 1;
	for(int i = 1; i < 10; ++i){
		int n = i + 1;
		for(int j = 1; j <= i; ++j){
			if (n - j - 1 < j - 1)
				break;
			for (int k = 0; k <= n - j - 1; ++k)
			f[i] += f[k];
		}
	}
	
	for(int i = 0; i < 10; ++i){
		cout << i << ":" << f[i] <<endl;	
	}
    return 0;
}

