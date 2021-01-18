#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main()
{
    #ifndef ONLINE_JUDGE
        freopen("input.txt","r",stdin);
        freopen("output.txt","w",stdout);
    #endif
    int cases; cin >> cases;
    for(int jj = 0; jj < cases; ++jj){
        int n; cin >> n;
        cout << n << endl;
        for(int i = 0; i < n; ++i)
        {
            cout << i + 1 << " ";
        }
        cout << endl;
    }
    return 0;
}