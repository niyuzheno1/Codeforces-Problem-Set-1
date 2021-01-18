#include <iostream>
#include <vector>
#include <string>
#include <cmath>
using namespace std;

long long contain(long long x, long long y){
    long long u = 0;
    while (x%y==0)
    {
        ++u;
        x/=y;
    }
    return u;

}

int main()
{
    #ifdef DEBUG
        freopen("input.txt","r",stdin);
        freopen("output.txt","w",stdout);
    #endif
    int t;
    cin >> t;
    while(t--){
        long long x, y;
        cin >> x >> y;
        vector<long long> factors;
        for(int i = 2; i <= sqrt(y)+1; ++i){
            if((y % i) == 0)
                factors.push_back(i);
        }
        for(int i = factors.size()-1; i >= 0; --i){
            long long d = factors[i];
            if(x % d == 0 && y % d == 0)
            {    

                if(contain(x,d) == contain(y,d))
                {
                    
                    y /= d;
                    x /= d;
                    break;
                }
            }
        }
        cout << x << endl;

        
    }
    return 0;
}