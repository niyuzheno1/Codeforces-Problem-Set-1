#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main()
{
    #ifdef DEBUG
        freopen("input.txt","r",stdin);
        freopen("output.txt","w",stdout);
    #endif
    int t;
    cin >>t;
    while(t--){
        int a,b,c,d;
        cin >> a >> b >> c >> d;
        cout << max(a+b,c+d)<<endl;
    }
    return 0;
}