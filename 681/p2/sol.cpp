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
    int x;
    cin >>x;
    cout << x; 
    return 0;
}