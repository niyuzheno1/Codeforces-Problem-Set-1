#include <iostream>
#include <vector>
#include <string>

using namespace std;

int gcd(int a, int b) {
   if (b == 0)
   return a;
   return gcd(b, a % b);
}

vector<int> a; 
vector<int> b; 


int main()
{
    #ifndef ONLINE_JUDGE
        freopen("input.txt","r",stdin);
        freopen("output.txt","w",stdout);
    #endif
    int n, m; cin >> n >> m;
    for(int i = 0; i < n; ++i)
    {
        int x; cin >> x;
        a.push_back(x);
    }
    for(int i = 0; i < m; ++i)
    {
        int x; cin >> x;
        b.push_back(x);
    }
    for(int i = 0; i < m; ++i)
    {
        int x = b[i];
        int ans = gcd(a[0] + x, a[1]+x);
        for(int j = 0; j < n; ++ j)
            ans = gcd(ans, a[j]+x);
        cout << ans << endl;
    }

    return 0;
}