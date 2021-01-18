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
        int lbracket = 0, rbracket = 0;
        for(int i = 0; i < s.length(); ++i){
            if(s[i] == '(') lbracket = i;
            if(s[i] == ')') rbracket = i;
        }
        int n = s.length();
        bool yes = false;
        
        // lbracket matches with i and rbracket matches with j
        for(int i = lbracket+1; i < n; ++i){
            for(int j = i+1; j < rbracket; ++j)
                if( j-i-1 % 2 == 0 && (i-lbracket-1) % 2 == 0 && (rbracket-j - 1) % 2 == 0 &&  (lbracket) % 2 == 0 && (n-rbracket-1) % 2 == 0){
                    yes = true;
                }
        }
        //lbracket matches with rbracket:
        

        if(yes) cout << "YES" <<endl;
        else cout << "NO" << endl;
         
    }
    return 0;
}