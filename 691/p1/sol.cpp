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
    int tcases; cin >> tcases; 
    for(int jj = 0; jj < tcases; ++ jj){
        int n; cin >> n;
        string a, b;
        cin >> a >> b;
        int cntx = 0, cnty = 0;
        for(int i = 0; i < n; ++i){
            if(a[i] > b[i])
                ++ cntx;
            if(a[i] < b[i])
                ++ cnty;
        }
        if(cntx > cnty) cout << "RED";
        else if (cntx < cnty) cout << "BLUE";
        else cout << "EQUAL";
        cout << endl;
    }
    return 0;
}