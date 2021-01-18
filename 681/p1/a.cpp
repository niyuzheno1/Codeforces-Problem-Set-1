#include <iostream>
#include <vector>
#include <string>

using namespace std;




int main()
{
    #ifdef DEBUG       
        freopen("input.txt","w",stdout);
 
    #endif
    cout << 100 << endl;
    for(int i = 1; i <= 100; ++i)
    {
        cout << i <<endl;
     }
   return 0;
}