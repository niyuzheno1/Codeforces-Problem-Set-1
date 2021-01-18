#include <iostream>
#include <vector>
#include <string>
using namespace std;

#define MAXN 2010

int goodfromleft[MAXN][MAXN];
int goodfromright[MAXN][MAXN];
int goodfromtop[MAXN][MAXN];
int goodfromlbottom[MAXN][MAXN];
int morelines[MAXN][MAXN];
int a[MAXN][MAXN];
int scanline[MAXN];
int sumx[MAXN];
int sumy[MAXN];
int n, k;
int getsumx(int x, int y){
    if(y < 0) return 0;
    int diff = x == 0? 0 : sumx[x-1];
    int biff = y >= n ? sumx[n-1]: sumx[y]; 
    return biff - diff;
}
int getsumy(int x, int y){
    if(y < 0) return 0;
    int diff = x == 0? 0 : sumy[x-1];
    int biff = y >= n ? sumy[n-1]: sumy[y];
    return biff - diff;
}

int main()
{
    #ifndef ONLINE_JUDGE
        freopen("input.txt","r",stdin);
        freopen("output.txt","w",stdout);
    #endif
    cin >> n >> k;
    for(int i = 0; i < n; ++i)
    {
        string s;
        cin >> s;
        for(int j = 0; j < n; ++j)
            a[i][j] = s[j] == 'B' ? 0 : 1;
    }
    for(int i = 0; i < n; ++i)
    {
        goodfromleft[i][0] = a[i][0] == 1 ? 1 : 0;
        for(int j = 1; j < n; ++j)
            goodfromleft[i][j] =(a[i][j] == 1) && goodfromleft[i][j-1];
    }
    for(int i = 0; i < n; ++i)
    {
        goodfromright[i][n-1] = a[i][n-1] == 1 ? 1 : 0;
        for(int j = n-2; j >= 0; --j)
            goodfromright[i][j] = (a[i][j] == 1) && goodfromright[i][j+1];
    }
    for(int i = 0; i < n; ++i) goodfromtop[0][i] = a[0][i] == 1 ? 1 : 0;
    for(int i = 0; i < n; ++i) goodfromlbottom[n-1][i] = a[n-1][i] == 1 ? 1 : 0;
    for(int i = 1; i < n; ++i)
        for(int j = 0; j < n; ++j)
            goodfromtop[i][j] = (a[i][j] == 1) && goodfromtop[i-1][j];
    for(int i = n-2; i >= 0; --i)
        for(int j = 0; j < n; ++j)
            goodfromlbottom[i][j] = (a[i][j] == 1) && goodfromlbottom[i+1][j];

    // top to bottom
    for(int i = 0; i < n; ++i)
    {
        for(int j = 0; j < n; ++j)
        {
            int gfb =  i + k < n ? goodfromlbottom[i + k][j] : 1;
            if((i == 0 || goodfromtop[i-1][j]) && gfb)
                scanline[j] = j == 0 ?  1 :  scanline[j-1] + 1;
            else
                scanline[j] = j == 0 ? 0 : scanline[j-1];
        }
        for(int j = 0; j < n-k+1; ++j)
        {
            int diff = j == 0 ? 0 :scanline[j-1];
            morelines[i][j] += scanline[j+k-1]-diff;
        }
    }
    //from left to right
    for(int i = 0; i < n; ++i)
    {
        for(int j = 0; j < n; ++j)
        {
            int gfr =  i + k < n ? goodfromright[j][i + k] : 1;
            if(( i == 0 || goodfromleft[j][i-1]) && gfr)
                scanline[j] = j == 0 ?  1 :  scanline[j-1] + 1;
            else
                scanline[j] = j == 0 ? 0 : scanline[j-1];
        }
        for(int j = 0; j < n-k+1; ++j)
        {
            int diff = j == 0 ? 0 :scanline[j-1];
            morelines[j][i] += scanline[j+k-1]-diff;
        }
    }
    for(int i = 0; i < n; ++i)
        sumx[i] = goodfromleft[i][n-1] ? 1 : 0;
    for(int i = 0; i < n; ++i)
        sumy[i] = goodfromtop[n-1][i] ? 1 : 0;
    for(int i = 0; i<n; ++i)
        sumx[i] = i != 0? sumx[i-1] +  sumx[i] : sumx[i];
    for(int i = 0; i<n; ++i)
        sumy[i] = i != 0? sumy[i-1] +  sumy[i] : sumy[i];
    int ans = 0;
    for(int i = 0; i < n; ++i )
        for(int j = 0 ; j < n; ++j){
            int a = getsumx(0,i-1);
            a += getsumy(0,j-1);
            a += getsumx(i+k,n);
            a += getsumy(j+k,n);
            a += morelines[i][j];
            ans = max(ans, a);
        }
    cout << ans;
    return 0;
}