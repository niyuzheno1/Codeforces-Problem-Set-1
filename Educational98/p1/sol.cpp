#include <iostream>
#include <vector>
#include <string>

using namespace std;

int abs(int x){
    if (x > 0)
    return x;
    return -x;
}

int main()
{
    #ifndef ONLINE_JUDGE
        freopen("input.txt","r",stdin);
        freopen("output.txt","w",stdout);
    #endif
    int tcases;
    cin >> tcases; 
    for(int jj = 0; jj < tcases; ++jj){
        int x,y;
        cin >> x >> y;
        if(x == y){
            cout << abs(x)+abs(y);
        }else{
            int z = abs(x-y)-1;
            cout <<  abs(x)+abs(y) + z;
        }
        cout <<endl;

    }

    return 0;
}