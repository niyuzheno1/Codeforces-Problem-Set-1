#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main()
{

    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    int t;
    cin >> t;
    for(int j = 0; j < t; ++j){
        string s;
        cin >> s;
        int ans = 0;
        int cnt = 0;
        for(int i = 0; i < s.length(); ++i){
            if(s[i] == 'v'){
                ++cnt;
            }else{
                ++ans;
                ans += cnt/2;
                cnt = 0;
            }
        }
        ans += cnt/2;
        cout << ans <<endl;
    }
    return 0;
}