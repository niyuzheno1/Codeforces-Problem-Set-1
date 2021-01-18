#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main()
{
    #ifndef ONLINE_JUDGE
        freopen("input.txt","r",stdin);
        freopen("output.txt","w",stdout);
    #endif
    int tcases = 0;
    cin >> tcases; 
    for(int jj = 0 ; jj  < tcases; ++ jj){
        int n,k;
        cin >> k >> n;
        vector<long long> a(n*k);
        for(int i = 0; i < n*k; ++i){
            cin >> a[i];
        }
        if( k % 2 == 0){
            int lower = k/2;
            int pointer = -1;
            int pointer2 = n*k;
            long long ans = 0;
            while(pointer2 > pointer){
                pointer += lower-1;
                pointer2 -= (k - lower+1);
                if(pointer2 < pointer)
                    break;
                ans += a[pointer2] ;
            }
            cout << ans << endl;
        }else{
            int lower = (k+1)/2;
            int pointer = -1 ; 
            int pointer2 = n * k ;
            long long ans = 0;
            while(pointer2 > pointer){
                pointer += lower-1;
                pointer2 -= (k - lower + 1);
                if(pointer2 < pointer)
                    break;
                ans += a[pointer2];
            }
            cout << ans << endl;
        }
    }
    return 0;
}