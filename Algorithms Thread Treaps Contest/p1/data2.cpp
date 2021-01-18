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
    freopen("input.txt","w",stdout);
    srand(time(0));
    int n = rand()%50+2;
    cout << n << endl;
    for(int i = 0; i < n;++i){
        int x, y;
        
        x = rand()%n+1;
        y = rand()%n+1;
        int a = min(x,y);
        int b = max(x,y);
        cout << a << " " << b << endl;
    }
}