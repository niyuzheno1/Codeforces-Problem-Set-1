#include <iostream>
#include <vector>
#include <string>
#include <stack>

using namespace std;
string s; 
        
int main()
{
    #ifndef ONLINE_JUDGE
        freopen("input.txt","r",stdin);
        freopen("output.txt","w",stdout);
    #endif
    int tcases;
    cin >> tcases; 
    while(tcases--){
        string t;
        cin >> s;
        int lbracket = 0, rbracket = 0, qmark = 0;
        for(int i = 0; i < s.length(); ++i){
            if(s[i] == '(') lbracket = i;
            if(s[i] == ')') rbracket = i;
            if(s[i] == '?') ++qmark;
        }
        int n = s.length();
        bool yes = false;
        if(qmark % 2 == 0 && lbracket < rbracket){
            yes = true;
        }else if( (lbracket < s.length()  && s[lbracket+1] == '?' && rbracket > 0 && s[rbracket-1] == '?') && qmark % 2 == 0){
            yes = true;
        }
        

        if(yes) cout << "YES" <<endl;
        else cout << "NO" << endl;
         
    }
    return 0;
}