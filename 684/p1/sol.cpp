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
        int n,c0,c1,h;
        cin >> n >> c0 >> c1 >> h;
        string s;
        cin >> s;
        if(c0 + h < c1){
            int costs = 0;
            for(int i = 0; i < n; ++i){
                if(s[i] == '0')
                    costs += c0;
                else
                    costs += c0+h;
            }
            cout << costs << endl;
        }else if(c1 + h < c0){
            int costs = 0;
            for(int i = 0; i < n; ++i){
                if(s[i] == '0')
                    costs += c1+h;
                else
                    costs += c1;
            }
            cout << costs << endl;
        }else {
            int costs = 0;
            for(int i = 0; i < n; ++i){
                if(s[i] == '0')
                    costs += c0;
                else
                    costs += c1;
            }
            cout << costs << endl;
        }
    }
    return 0;
}