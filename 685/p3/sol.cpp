#include <iostream>
#include <vector>
#include <string>

using namespace std;

#define MAXN 30
int sd[MAXN];
int td[MAXN];

int main()
{
    #ifndef ONLINE_JUDGE
        freopen("input.txt","r",stdin);
        freopen("output.txt","w",stdout);
    #endif
    int tcases;
    cin >>  tcases;
    for (int jj = 0 ; jj < tcases; ++ jj){
        int n, k;
        cin >> n >> k;
        string s; 
        string t;
        cin >> s >> t;
        for(int i = 0; i < MAXN; ++i)
            sd[i] = td[i] = 0;
        for(int i = 0; i < n; ++i){
            sd[s[i]-'a'] = sd[s[i]-'a'] + 1;
            td[t[i]-'a'] = td[t[i]-'a'] + 1;
        }
        int maxm = 'z' -'a'+1;
        for(int i = 0; i < maxm; ++i)
            if(td[i] > 0){
                int x = i;
                int tx = sd[x] - td[x];
                int ty = sd[x];
                if (tx < 0) {
                    td[x] -= sd[x];
                    sd[x] = 0;
                }else{
                    td[x] = 0;
                    sd[x] = tx;
                }
            }
        for(int i = 0; i< maxm; ++i)
            for(int j = i + 1; j < maxm; ++j){
                if(sd[i] >= k && td[j] >= k){
                    int amount = min(sd[i], td[j]) / k;
                    sd[i] = sd[i] - amount * k;
                    td[j] = td[j] - amount * k;
                }
            }
        bool flag = true;
        for(int i = 0;  i < maxm; ++i){
            if(sd[i] >0)
                flag = false;
            if(td[i] >0)
                flag = false;
        
        }
        if(flag == true){
            cout << "Yes" <<endl;
        }else{
            cout <<"No"<<endl;
        }

    }
    return 0;
}