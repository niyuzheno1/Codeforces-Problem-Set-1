#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include <map>
using namespace std;


int main()
{
    #ifndef ONLINE_JUDGE
        freopen("input.txt","r",stdin);
        freopen("output.txt","w",stdout);
    #endif
    
    string s;
    while(!cin.eof()){
        getline(cin,s);
        cout << s << "," ;
    }

    return 0;
}