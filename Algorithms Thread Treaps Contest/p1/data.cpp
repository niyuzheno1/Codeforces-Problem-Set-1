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
    cout << 500000 << endl;
    for(int i = 0; i < 500000; ++i){
        cout << 0 << " " << 250000 << endl;
    }    
}