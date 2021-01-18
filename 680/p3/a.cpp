#include <iostream>
#include <vector>
#include <string>

using namespace std;

int gcd(int a, int b) {
   if (b == 0)
   return a;
   return gcd(b, a % b);
}

int main()
{
    int ttt;
    scanf("%d", &ttt);
    while(ttt--){
        int xxx, yyy;
        scanf("%d%d",&xxx,&yyy);
        int a = gcd(xxx,yyy);
        if(a == 1){
            printf("%d\n",xxx);
        }else{
            int  b = xxx/a;

            if(yyy % b == 0){
                int kk = gcd(a,yyy/b);
                printf("%d\n",xxx/kk);
            }else{
                
                printf("%d\n",xxx);
            }
        }
    }
    return 0;
}