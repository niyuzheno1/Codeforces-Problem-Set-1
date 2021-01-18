#include <iostream>
#include <vector>
#include <string>

using namespace std;

int n;
void shandom_ruffle(int a, int b, vector<int> & array) {
  int bStart=b;
  while (a<bStart && b<=n) {
    swap(array[a], array[b]); //swap the values at indecies a and b
    a++;
    b++;
  }
}



int main()
{
    #ifndef ONLINE_JUDGE
        freopen("input.txt","r",stdin);
        freopen("output2.txt","w",stdout);
    #endif
    cin >> n;
    vector<int> a;
    for(int i = 0; i <= n; ++i){
        a.push_back(i);
    }
    for(int i = 0; i < n; ++ i){
        int x,y;
        cin >> x >> y;
        shandom_ruffle(x,y,a);
        
        
    }
    cout << a[1];
    for(int i= 2; i <= n; ++i)
            cout << " " << a[i] ;
        cout << endl;

    return 0;
}