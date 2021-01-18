#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

int main()
{
    #ifdef DEBUG
        freopen("input.txt","r",stdin);
        freopen("output.txt","w",stdout);
    #endif
    int cases = 0;
    cin >> cases;
    while(cases --){
        int n,x;
        cin >> n >> x;
        vector<int> a,b;
        for(int i = 0; i < n; ++i){
            int xx;
            cin >> xx;
            a.push_back(xx);
        }
        for(int i = 0; i < n; ++i){
            int xx;
            cin >> xx;
            b.push_back(xx);
        }
        int flag = true;
        for(int i = 0; i < n; ++i)
        {
            int crite = a[i] + b[n-i-1];
            if(crite > x){
                flag = false;
            }
        }
        if(!flag){
            cout << "No" << endl;
        }else{
            cout << "Yes"<<endl;
        }
    }
    return 0;
}