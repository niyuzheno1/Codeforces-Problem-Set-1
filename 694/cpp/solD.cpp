#include <iostream>
#include <vector>
#include <string>

using namespace std;
int n, k, cards;
#define MAXN 100010
int a[MAXN];

void ask(int x){
    ++x;
    printf("? %d\n", x);
    fflush(stdout);
    cin >> cards;
}
int md(int x){
    while(x < 0)
    {  
        x += n;
    }
    return (x%n);
}
void set(int x, int r){
    for(int i = x-r; i <= x+r; ++i){
        a[md(x)] = 1;
    }    
}



int main()
{
    #ifndef ONLINE_JUDGE
        freopen("input.txt","r",stdin);
        freopen("output.txt","w",stdout);
    #endif
    cin >> n >> k;
    int range = 0;
    int found_t = 0, idx = 0, nidx = 0;
    for(int i = 0; i < 1000; ++ i){  //[-range, + range]
        ask(idx);
        if(cards == 1 ){
            found_t = 1;
        }
        if(cards == -1){
            found_t = -1;
        }
        if(cards == 2){
            ask(idx+range);
            if(cards == 3){
                
            }
        }
        idx = nidx;
    }
    return 0;
}