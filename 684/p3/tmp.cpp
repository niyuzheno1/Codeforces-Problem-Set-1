#include <iostream>
#include <vector>
#include <string>
#include <map>

using namespace std;
#define MAXN 110
int a[MAXN][MAXN];
int outputs[MAXN * MAXN][6];
int main()
{
    #ifndef ONLINE_JUDGE
        freopen("input.txt","r",stdin);
        freopen("output.txt","w",stdout);
    #endif
    int tcases;
    cin >> tcases;
    for(int jj = 0 ; jj < tcases; ++jj){
        int n,m;
        cin >> n >> m;
        vector<pair<int,int>> vp;
        for (int i = 0; i < n; ++i){
            string s;
            cin >> s;
            for(int j = 0; j < m ; ++ j){
                if(s[j] == '1'){
                    vp.push_back(make_pair(i,j));
                    a[i][j] = 1;
                }else{
                    a[i][j]  = 0;
                }
                
            }
        }
        int ans = 0;
        int xi = 0;
        for(xi = 0; xi < vp.size(); xi += 2){
            if(xi + 1 >= vp.size())
                break;
            outputs[ans][0] = vp[xi].first;
            outputs[ans][1] = vp[xi].second;   
            outputs[ans][2] = vp[xi+1].first;
            outputs[ans][3] = vp[xi+1].second; 
            outputs[ans][4] = n-1;
            outputs[ans][5] = m-1; 
            ++ ans;
            a[vp[xi].first][ vp[xi].second] ^= 1;
            a[vp[xi+1].first] [vp[xi+1].second] ^= 1;
            a[n-1] [m-1] ^= 1;
        }
        vector<pair<int,int>> ones;
        vector<pair<int,int>> zeros;
        for(int i = 0; i < n ; ++i){
            for(int j = 0; j < m ; ++ j)
                if(a[i][j] == 1)
                    ones.push_back(make_pair(i,j));
                else{
                    if(zeros.size() < 6)
                        zeros.push_back(make_pair(i,j));
                }
        }
         
        if (ones.size() != 3 && ones.size() != 0){
            int st = 0;
            if(ones.size() == 1){
                pair<int,int> t = ones.back();
                outputs[ans][0] = t.first;
                outputs[ans][1] = t.second;   
                outputs[ans][2] = zeros[0].first;
                outputs[ans][3] = zeros[0].second; 
                outputs[ans][4] = zeros[1].first;
                outputs[ans][5] = zeros[1].second; 
                ++ ans;
                zeros.push_back(ones.back());
                ones.pop_back();
                ones.push_back(zeros[0]);
                ones.push_back(zeros[1]);
                st = 2;
            }
            pair<int,int> t = ones.back();
            outputs[ans][0] = t.first;
            outputs[ans][1] = t.second;   
            outputs[ans][2] = zeros[st].first;
            outputs[ans][3] = zeros[st].second; 
            outputs[ans][4] = zeros[st+1].first;
            outputs[ans][5] = zeros[st+1].second; 
            ++ans;
            ones.pop_back();
            ones.push_back(zeros[st]);
            ones.push_back(zeros[st+1]);
           
        }
        for(int i = 0; i < ones.size(); i += 3){

            outputs[ans][0] = ones[0].first;
            outputs[ans][1] = ones[0].second;   
            outputs[ans][2] = ones[1].first;
            outputs[ans][3] = ones[1].second; 
            outputs[ans][4] = ones[2].first;
            outputs[ans][5] = ones[2].second; 
            ++ans;
        }
        cout << ans << endl;
        for(int i = 0; i < ans; ++i){
            cout << outputs[i][0]+1 << " " << outputs[i][1]+1 << " ";
            cout << outputs[i][2]+1 << " " << outputs[i][3]+1 << " ";
            cout << outputs[i][4] +1<< " " << outputs[i][5]+1 << endl;
        }

    }
    return 0;
}