#include <iostream>
#include <vector>
#include <string>

using namespace std;

int abs(int x){
    if(x < 0)
        return -x;
    return x;
}



int main()
{
    #ifndef ONLINE_JUDGE
        freopen("input.txt","r",stdin);
        freopen("output.txt","w",stdout);
    #endif
    int tcases;
    cin >> tcases; 
    for(int jj = 0; jj < tcases; ++ jj){
        int n,m,r,c;
        cin >> n >> m >> r >> c;
        int a = max(abs(n-r), abs(1-r));
        int b = max(abs(m-c), abs(1-c));
        cout << a + b <<endl;
    }
    return 0;
}