#include <iostream>
#include <vector>
#include <string>
#include <stack>
using namespace std;


#define MAXN 200010

bool visited[MAXN];

vector<int> edges[MAXN];
stack<int> st; 
stack<int> st2; 
vector<int> circle;
int circlecount[MAXN];

bool found = false;

void dfs(int x, int p){
    visited[x] = 1;
    st.push(x);
    for(int i = 0; i < edges[x].size(); ++ i){
        int y = edges[x][i];
        if(!visited[y])
            dfs(y, x);
        else if(y != p && !found){
            found = true;
            while(!st.empty() && st.top() != y){
                circle.push_back(st.top());
                st2.push(st.top());
                st.pop();
            }
            circle.push_back(y);
            while(!st2.empty()){
                st.push(st2.top());
                st2.pop();
            }
        }
    }
    st.pop();
}



void dfs2(int x, int & p){
    ++p;
    visited[x] = 1;
    st.push(x);
    for(int i = 0; i < edges[x].size(); ++ i){
        int y = edges[x][i];
        if(!visited[y])
            dfs2(y, p);
    }
}


typedef long long ll;

int main()
{
    #ifndef ONLINE_JUDGE
        freopen("input.txt","r",stdin);
        freopen("output.txt","w",stdout);
    #endif
    int tcases;
    cin >> tcases;
    for(int jj = 0 ; jj < tcases; ++jj){
        int n ;
        found = false;
        cin >> n;
        circle.clear();
        for(int i = 0; i <= n+2; ++i){
            edges[i].clear();
            visited[i] = 0;
        }
        for(int i = 0; i < n; ++i){
            int x, y; cin >> x >> y;
            edges[x].push_back(y);edges[y].push_back(x);
        }
        dfs(1, -1);
        for(int i = 0; i <= n+2; ++i){
            visited[i] = 0;
            circlecount[i] = 0;
        }
        int m = circle.size();
        for(int i = 0; i < m; ++i)
            visited[circle[i]] = 1;
        
        for(int i = 0; i < m; ++i){
            dfs2(circle[i],circlecount[i]);
           
        }
        ll ans = 0;
        ll sum = 0;
        for(int i = 0; i < m; ++i){
            ll tmp = circlecount[i];
            sum += tmp;
            tmp = tmp * (tmp-1) / 2;
            ans += tmp;
        }
        for(int i = 0; i < m; ++i){
            ll tmp = circlecount[i];
            ans += (sum-tmp)*tmp;
        } 
        cout << ans <<endl;
    }
    return 0;
}