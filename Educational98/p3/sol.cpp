#include <iostream>
#include <vector>
#include <string>
#include <stack>
using namespace std;

int main()
{
    #ifndef ONLINE_JUDGE
        freopen("input.txt","r",stdin);
        freopen("output.txt","w",stdout);
    #endif
    int n;
    cin >> n;
    for(int jj = 0; jj < n; ++jj){
        string s;
        cin >> s;
        stack<int> s1;
        stack<int> s2;
        int ans = 0;
        for(int i = 0; i < s.length(); ++i){
            if(s[i] == '('){
                s1.push(1);
            }
            else if(s[i] == '['){
                s2.push(1);
            }else if (s[i] == ')'){
                if(!s1.empty()){
                    s1.pop();
                    ++ans;
                }
            }else if (s[i] == ']'){
                if(!s2.empty()){
                    s2.pop();
                    ++ans;
                }
            }
        }
        cout << ans <<endl;
    }
    return 0;
}