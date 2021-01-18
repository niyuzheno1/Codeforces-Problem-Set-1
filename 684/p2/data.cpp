#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main()
{
    #ifndef ONLINE_JUDGE
        freopen("input.txt","w",stdout);
    #endif
    int k= 6, n=4;
    cout << 1 << endl;
    cout << k  << endl << n << endl;
    for (int i = 0; i < k * n; ++i){
        cout << (i + 1) * 2 <<endl;
    }
    
    return 0;
}