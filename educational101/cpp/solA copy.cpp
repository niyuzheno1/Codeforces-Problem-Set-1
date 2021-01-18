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
    int tcases;
    cin >> tcases; 
    while(tcases--){
        string s; 
        string t;
        cin >> s;
        stack<char> st;
        int n = s.length();
        int u = -2;
        for(int i = 1; i < n; ++i){
            if(s[i] == ')' && (s[i-1] == '?'  || s[i-1] == '(') ){
                u = i-1;
            }
        }
        for(int i = 0 ; i < n; ++i){
            if(i == u || i == u + 1) continue;
            t += s[i];
        }
        s = t;
        for(int i = 0; i < n; ++i){
            if(s[i] == '?'){
                if( !st.empty() && (st.top() == '?' || st.top() == '(' ) ){
                    st.pop();
                }else{
                    st.push('?');
                }
            }
            if(s[i] == '('){
                st.push('(');
            }
            if(s[i] == ')'){
                if(!st.empty() &&  (st.top() == '?' || st.top() == '(')){
                    st.pop();
                }else{
                    st.push(')');
                }
            }
        }
        if(st.empty())
            cout << "YES" << endl;
        else
        {
            cout << "No" <<endl;
        }
         
    }
    return 0;
}