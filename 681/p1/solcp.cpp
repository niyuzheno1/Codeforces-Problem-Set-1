#include <iostream>
#include <vector>
#include <string>

using namespace std;

int a[1000];

int gcd(int a, int b) {
   if (b == 0)
   return a;
   return gcd(b, a % b);
}

bool list(int x,int n){
    vector<int> ans;
    ans.push_back(x);
    int skip = n;
    for(int times = 1; times <= 3; ++ times)
        for(int i = 1; i<=400; ++i){
                int flag = 0;
                for(int j = 0; j < ans.size() ; ++j){
                    if((ans[j] % i  == 0)  || (i % ans[j] == 0) || (gcd(ans[j],i)==1)){
                        flag = 1;
                    }
                }
                if(!flag){
                    if(skip > 0){
                        --skip;
                        continue;
                    }
                    ans.push_back(i);
                }
        }
    if(ans.size() == n){
        for(int i = 0; i < ans.size(); ++i)
            cout << ans[i] << " ";
        cout << endl;
        return true;
    }
    return false;
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
       int n;
       cin>>n;
       for(int i = 1;i<=4*n;++i)
        if(list(i,n))
            break;
    }
    return 0;
}