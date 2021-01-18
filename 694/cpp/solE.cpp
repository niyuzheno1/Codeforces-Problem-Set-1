#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;
#define MAXA 1000010
int minprime[MAXA];
vector<int> p;
typedef vector<int> vi;
int main()
{
    #ifndef ONLINE_JUDGE
        freopen("input.txt","r",stdin);
        freopen("output.txt","w",stdout);
    #endif
    int tcases; 
    cin >> tcases;
    for(int i = 2; i < MAXA; ++i) minprime[i] = -1;
  
    for(int i = 2; i <MAXA; ++i){
        if(minprime[i] == -1){
            minprime[i] = i;
           
        }else{
            continue;
        }
        int u = 2*i;
        while(u < MAXA){
            if(minprime[u] == -1)
                minprime[u] = i;
            u += i; 
        }
    }
    while(tcases--){
        int n; cin >>n;
        vector<vi> a;
        for(int i = 0; i < n; ++ i){
           int x; cin >> x;
           vi r; 
           for(; x != 1; ){
               int cnt = 0;
               int eminprime = minprime[x]; 
               while(x%eminprime == 0){
                   cnt = cnt+1;
                   cnt %= 2;
                   x /= eminprime;
               }
               if(cnt == 1){
                   r.push_back(eminprime);
               }
           }
           a.push_back(r);
        }
        sort(a.begin(),a.end());
        int maxsize = 0, evensize = 0;
        for(int i = 0; i < n; ){
            int j = i+1;
            while(j < n && a[j] == a[i]) ++ j;
            maxsize = max(maxsize,(j-i));
            if(a[i].size() == 0 || (j-i)%2 == 0){
                evensize += (j-i);
            }
            i = j;
        }
        int q;
        cin >> q;
        for(int i = 0; i < q; ++i){
            long long ux; cin >> ux;
            if(ux == 0){
                cout << maxsize <<endl;
            }else{
                cout << max(evensize,maxsize)<<endl;
            }
        }
    }
    return 0;
}