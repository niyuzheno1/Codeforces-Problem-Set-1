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
    //1 ; 1, 1 ; 1, 1 , 1
    int t;
    cin >> t;
    for(int jj = 0; jj < t; ++jj){
        int n;
        cin >> n;
        for(int i = 0; i < n; ++i){
            cout << 1 << " ";
        }
        cout<<endl;
    }
    return 0;
}