#include <iostream>
#include <vector>
#include <string>

using namespace std;

int a[1000];

int gcd(int a, int b) {
   if (b == 0)
   return a;
   return gcd(b, a % b);
}

bool list(int x,int n){
    vector<int> ans;
    ans.push_back(x);
    int skip = 0;
        skip = n;
    
    
    for(int times = 1; times <= 3; ++ times)
        for(int i = 1; i<=4*n; ++i){
                int flag = 0;
                for(int j = 0; j < ans.size() ; ++j){
                    if((ans[j] % i  == 0)  || (i % ans[j] == 0) || (gcd(ans[j],i)==1)){
                        flag = 1;
                    }
                }
                if(!flag){
                    if(skip > 0){
                        --skip;
                        continue;
                    }
                    ans.push_back(i);
                }
        }
    if(ans.size() == n){
        for(int i = 0; i < ans.size(); ++i)
            cout << ans[i] << " ";
        cout << endl;
        return true;
    }
    return false;
}

const int table[] =
{
    1,4,6,4,10,6,4,10,14,6,12,16,18,20,14,10,16,18,22,24,14,10,18,22,24,26,28,16,8,28,30,12,18,20,22,26,12,22,26,28,30,32,34,18,20,12,26,28,30,32,34,38,40,18,22,16,34,36,38,40,42,44,24,26,28,30,12,28,30,32,34,38,40,42,44,46,18,26,8,42,44,46,50,52,12,18,20,28,30,34,38,20,34,36,38,42,44,46,48,50,52,54,56,30,32,16,42,44,46,50,52,54,56,58,60,24,34,36,38,40,16,44,46,50,52,54,56,58,60,62,24,34,36,38,40,42,16,46,50,52,54,56,58,60,62,66,68,24,36,38,40,42,44,20,42,44,46,48,50,52,54,56,58,62,64,66,68,70,72,30,38,20,44,46,48,50,52,54,56,58,62,64,66,68,70,72,74,76,30,42,24,42,44,46,50,52,54,56,58,60,62,64,66,68,70,74,76,78,80,36,20,46,48,50,52,54,56,58,62,64,66,68,70,72,74,76,78,82,84,30,44,20,48,50,52,54,56,58,62,64,66,68,70,72,74,76,78,82,84,86,88,30,46,24,46,50,52,54,56,58,60,62,64,66,68,70,74,76,78,80,82,84,86,88,90,36,24,50,52,54,56,58,60,62,64,66,68,70,74,76,78,80,82,84,86,88,90,92,94,36,28,54,58,60,62,64,66,68,70,72,74,76,78,80,82,86,88,90,92,94,96,98,100,42,52,24,52,54,56,58,60,62,64,66,68,70,74,76,78,80,82,84,86,88,90,92,94,98,100,102,36,24,54,56,58,60,62,64,66,68,70,74,76,78,80,82,84,86,88,90,92,94,98,100,102,104,106,36,28,62,64,66,68,70,72,74,76,78,80,82,86,88,90,92,94,96,98,100,102,104,106,108,110,42,58,60,32,72,74,76,78,80,82,84,86,88,90,92,94,98,100,102,104,106,108,110,112,114,116,48,60,62,66,68,70,28,64,66,68,70,72,74,76,78,80,82,86,88,90,92,94,96,98,100,102,104,106,108,110,114,116,118,120,42,62,28,66,68,70,72,74,76,78,80,82,86,88,90,92,94,96,98,100,102,104,106,108,110,114,116,118,120,122,124,42,64,32,78,80,82,84,86,88,90,92,94,98,100,102,104,106,108,110,112,114,116,118,120,122,124,126,48,66,68,70,72,74,76,32,80,82,84,86,88,90,92,94,98,100,102,104,106,108,110,112,114,116,118,120,122,124,126,130,132,48,68,70,72,74,76,78,32,82,84,86,88,90,92,94,98,100,102,104,106,108,110,112,114,116,118,120,122,124,126,130,132,134,136,48,70,72,74,76,78,80,32,84,86,88,90,92,94,98,100,102,104,106,108,110,112,114,116,118,120,122,124,126,130,132,134,136,138,140,48,72,74,76,78,80,82,36,68,70,74,76,78,80,82,84,86,88,90,92,94,96,98,100,102,104,106,110,112,114,116,118,120,122,124,126,128,130,132,134,138,142,54,44,78,80,82,84,86,90,92,94,96,98,100,102,104,106,108,110,112,114,116,118,120,122,124,126,128,130,134,136,138,140,142,144,146,148,66,76,36,70,74,76,78,80,82,84,86,88,90,92,94,96,98,100,102,104,106,110,112,114,116,118,120,122,124,126,128,130,132,134,136,138,142,146,150,54,36,74,76,78,80,82,84,86,88,90,92,94,96,98,100,102,104,106,110,112,114,116,118,120,122,124,126,128,130,132,134,136,138,140,142,146,150,154,54,40,82,84,86,88,90,92,94,96,98,100,102,104,106,108,110,112,114,116,118,122,124,126,128,130,132,134,136,138,140,142,144,146,148,150,152,154,156,158,60,40,84,86,88,90,92,94,96,98,100,102,104,106,108,110,112,114,116,118,122,124,126,128,130,132,134,136,138,140,142,144,146,148,150,152,154,156,158,162,164,60,44,90,92,94,96,98,100,102,104,106,108,110,112,114,116,118,120,122,124,126,128,130,134,136,138,140,142,144,146,148,150,152,154,156,158,160,162,164,166,168,66,86,40,86,88,90,92,94,96,98,100,102,104,106,108,110,112,114,116,118,122,124,126,128,130,132,134,136,138,140,142,144,146,148,150,152,154,156,158,162,164,166,168,170,60,40,88,90,92,94,96,98,100,102,104,106,108,110,112,114,116,118,122,124,126,128,130,132,134,136,138,140,142,144,146,148,150,152,154,156,158,162,164,166,168,170,172,174,60,40,90,92,94,96,98,100,102,104,106,108,110,112,114,116,118,122,124,126,128,130,132,134,136,138,140,142,144,146,148,150,152,154,156,158,162,164,166,168,170,172,174,176,178,60,44,98,100,102,104,106,108,110,112,114,116,118,120,122,124,126,128,130,134,136,138,140,142,144,146,148,150,152,154,156,158,160,162,164,166,168,170,172,174,178,180,182,184,66,94,96,48,86,88,90,92,94,98,100,102,104,106,108,110,112,114,116,118,120,122,124,126,128,130,132,134,136,138,140,142,146,148,150,152,154,156,158,160,162,164,166,168,170,174,178,182,186,72,44,100,102,104,106,108,110,112,114,116,118,120,122,124,126,128,130,134,136,138,140,142,144,146,148,150,152,154,156,158,160,162,164,166,168,170,172,174,178,180,182,184,186,188,190,192,66,98,44,102,104,106,108,110,112,114,116,118,120,122,124,126,128,130,134,136,138,140,142,144,146,148,150,152,154,156,158,160,162,164,166,168,170,172,174,178,180,182,184,186,188,190,192,194,196,66,100,48,90,92,94,98,100,102,104,106,108,110,112,114,116,118,120,122,124,126,128,130,132,134,136,138,140,142,146,148,150,152,154,156,158,160,162,164,166,168,170,172,174,176,178,182,186,190,194,198,72,48,92,94,98,100,102,104,106,108,110,112,114,116,118,120,122,124,126,128,130,132,134,136,138,140,142,146,148,150,152,154,156,158,160,162,164,166,168,170,172,174,176,178,180,182,186,190,194,198,202,72,52,110,112,114,116,118,120,122,124,126,128,130,132,134,136,138,140,142,144,146,148,150,152,154,158,160,162,164,166,168,170,172,174,176,178,180,182,184,186,188,190,192,194,196,198,200,202,204,206,78,106,108,48,94,98,100,102,104,106,108,110,112,114,116,118,120,122,124,126,128,130,132,134,136,138,140,142,146,148,150,152,154,156,158,160,162,164,166,168,170,172,174,176,178,180,182,184,186,190,194,198,202,206,210,72,48,98,100,102,104,106,108,110,112,114,116,118,120,122,124,126,128,130,132,134,136,138,140,142,146,148,150,152,154,156,158,160,162,164,166,168,170,172,174,176,178,180,182,184,186,188,190,194,198,202,206,210,214,72,52,116,118,120,122,124,126,128,130,132,134,136,138,140,142,144,146,148,150,152,154,158,160,162,164,166,168,170,172,174,176,178,180,182,184,186,188,190,192,194,196,198,200,202,204,206,210,212,214,216,218,220,78,112,114,48,100,102,104,106,108,110,112,114,116,118,120,122,124,126,128,130,132,134,136,138,140,142,146,148,150,152,154,156,158,160,162,164,166,168,170,172,174,176,178,180,182,184,186,188,190,194,196,198,202,206,210,214,218,222,72,48,102,104,106,108,110,112,114,116,118,120,122,124,126,128,130,132,134,136,138,140,142,146,148,150,152,154,156,158,160,162,164,166,168,170,172,174,176,178,180,182,184,186,188,190,194,196,198,200,202,206,210,214,218,222,226,72,48,104,106,108,110,112,114,116,118,120,122,124,126,128,130,132,134,136,138,140,142,146,148,150,152,154,156,158,160,162,164,166,168,170,172,174,176,178,180,182,184,186,188,190,194,196,198,200,202,204,206,210,214,218,222,226,230,72,60,96,98,100,102,104,106,108,110,112,114,116,118,122,124,126,128,130,132,134,136,138,140,142,144,146,148,150,152,154,156,158,160,162,164,166,168,170,172,174,176,178,182,184,186,188,190,194,198,202,206,210,214,218,222,226,230,234,90,48,106,108,110,112,114,116,118,120,122,124,126,128,130,132,134,136,138,140,142,146,148,150,152,154,156,158,160,162,164,166,168,170,172,174,176,178,180,182,184,186,188,190,194,196,198,200,202,204,206,208,210,214,218,222,226,230,234,238,72,48,108,110,112,114,116,118,120,122,124,126,128,130,132,134,136,138,140,142,146,148,150,152,154,156,158,160,162,164,166,168,170,172,174,176,178,180,182,184,186,188,190,194,196,198,200,202,204,206,208,210,212,214,218,222,226,230,234,238,242,72,56,124,126,128,130,132,134,136,138,140,142,144,146,148,150,152,154,156,158,160,162,164,166,170,172,174,176,178,180,182,184,186,188,190,192,194,196,198,200,202,204,206,208,210,212,214,216,218,220,222,226,228,230,232,234,236,238,240,242,244,246,84,56,126,128,130,132,134,136,138,140,142,144,146,148,150,152,154,156,158,160,162,164,166,170,172,174,176,178,180,182,184,186,188,190,192,194,196,198,200,202,204,206,208,210,212,214,216,218,220,222,226,228,230,232,234,236,238,240,242,244,246,248,250,84,60,104,106,108,110,112,114,116,118,122,124,126,128,130,132,134,136,138,140,142,144,146,148,150,152,154,156,158,160,162,164,166,168,170,172,174,176,178,182,184,186,188,190,192,194,196,198,200,202,204,206,210,214,218,222,226,230,234,238,242,246,250,254,90,64,146,148,150,152,154,156,158,160,162,164,166,168,170,172,174,176,178,180,182,184,186,188,190,194,196,198,200,202,204,206,208,210,212,214,216,218,220,222,224,226,228,230,232,234,236,238,240,242,244,246,248,250,252,254,258,260,96,132,134,136,138,140,142,144,60,106,108,110,112,114,116,118,122,124,126,128,130,132,134,136,138,140,142,144,146,148,150,152,154,156,158,160,162,164,166,168,170,172,174,176,178,182,184,186,188,190,192,194,196,198,200,202,204,206,208,210,214,218,222,226,230,234,238,242,246,250,254,258,262,90,60,108,110,112,114,116,118,122,124,126,128,130,132,134,136,138,140,142,144,146,148,150,152,154,156,158,160,162,164,166,168,170,172,174,176,178,182,184,186,188,190,192,194,196,198,200,202,204,206,208,210,212,214,218,222,226,230,234,238,242,246,250,254,258,262,266,90,64,152,154,156,158,160,162,164,166,168,170,172,174,176,178,180,182,184,186,188,190,194,196,198,200,202,204,206,208,210,212,214,216,218,220,222,224,226,228,230,232,234,236,238,240,242,244,246,248,250,252,254,258,260,262,264,266,268,270,272,96,138,140,142,144,146,148,150,64,154,156,158,160,162,164,166,168,170,172,174,176,178,180,182,184,186,188,190,194,196,198,200,202,204,206,208,210,212,214,216,218,220,222,224,226,228,230,232,234,236,238,240,242,244,246,248,250,252,254,258,260,262,264,266,268,270,272,274,276,96,140,142,144,146,148,150,152,64,156,158,160,162,164,166,168,170,172,174,176,178,180,182,184,186,188,190,194,196,198,200,202,204,206,208,210,212,214,216,218,220,222,224,226,228,230,232,234,236,238,240,242,244,246,248,250,252,254,258,260,262,264,266,268,270,272,274,276,278,280,96,142,144,146,148,150,152,154,64,158,160,162,164,166,168,170,172,174,176,178,180,182,184,186,188,190,194,196,198,200,202,204,206,208,210,212,214,216,218,220,222,224,226,228,230,232,234,236,238,240,242,244,246,248,250,252,254,258,260,262,264,266,268,270,272,274,276,278,280,282,284,96,144,146,148,150,152,154,156,68,150,152,154,156,158,160,162,164,166,168,170,172,174,176,178,180,182,184,186,188,190,192,194,196,198,200,202,206,208,210,212,214,216,218,220,222,224,226,228,230,232,234,236,238,240,242,244,246,248,250,252,254,256,258,260,262,264,266,268,270,274,276,278,280,282,284,286,288,102,146,148,68,152,154,156,158,160,162,164,166,168,170,172,174,176,178,180,182,184,186,188,190,192,194,196,198,200,202,206,208,210,212,214,216,218,220,222,224,226,228,230,232,234,236,238,240,242,244,246,248,250,252,254,256,258,260,262,264,266,268,270,274,276,278,280,282,284,286,288,290,292,102,148,150,76,154,156,158,160,162,164,166,168,170,172,174,176,178,180,182,184,186,188,190,192,194,196,198,200,202,204,206,208,210,212,214,216,218,220,222,224,226,230,232,234,236,238,240,242,244,246,248,250,252,254,256,258,260,262,264,266,268,270,272,274,276,278,280,282,284,286,288,290,292,294,296,114,150,68,154,156,158,160,162,164,166,168,170,172,174,176,178,180,182,184,186,188,190,192,194,196,198,200,202,206,208,210,212,214,216,218,220,222,224,226,228,230,232,234,236,238,240,242,244,246,248,250,252,254,256,258,260,262,264,266,268,270,274,276,278,280,282,284,286,288,290,292,294,296,298,300,102,152,68,156,158,160,162,164,166,168,170,172,174,176,178,180,182,184,186,188,190,192,194,196,198,200,202,206,208,210,212,214,216,218,220,222,224,226,228,230,232,234,236,238,240,242,244,246,248,250,252,254,256,258,260,262,264,266,268,270,274,276,278,280,282,284,286,288,290,292,294,296,298,300,302,304,102,154,72,134,136,138,140,142,146,148,150,152,154,156,158,160,162,164,166,168,170,172,174,176,178,180,182,184,186,188,190,192,194,196,198,200,202,204,206,208,210,212,214,218,220,222,224,226,228,230,232,234,236,238,240,242,244,246,248,250,252,254,256,258,260,262,264,266,270,274,278,282,286,290,294,298,302,306,108,76,162,164,166,168,170,172,174,176,178,180,182,184,186,188,190,192,194,196,198,200,202,204,206,208,210,212,214,216,218,220,222,224,226,230,232,234,236,238,240,242,244,246,248,250,252,254,256,258,260,262,264,266,268,270,272,274,276,278,280,282,284,286,288,290,292,294,296,298,300,302,306,308,310,312,114,158,160,72,136,138,140,142,146,148,150,152,154,156,158,160,162,164,166,168,170,172,174,176,178,180,182,184,186,188,190,192,194,196,198,200,202,204,206,208,210,212,214,218,220,222,224,226,228,230,232,234,236,238,240,242,244,246,248,250,252,254,256,258,260,262,264,266,268,270,274,278,282,286,290,294,298,302,306,310,314,108,72,138,140,142,146,148,150,152,154,156,158,160,162,164,166,168,170,172,174,176,178,180,182,184,186,188,190,192,194,196,198,200,202,204,206,208,210,212,214,218,220,222,224,226,228,230,232,234,236,238,240,242,244,246,248,250,252,254,256,258,260,262,264,266,268,270,272,274,278,282,286,290,294,298,302,306,310,314,318,108,72,140,142,146,148,150,152,154,156,158,160,162,164,166,168,170,172,174,176,178,180,182,184,186,188,190,192,194,196,198,200,202,204,206,208,210,212,214,218,220,222,224,226,228,230,232,234,236,238,240,242,244,246,248,250,252,254,256,258,260,262,264,266,268,270,272,274,276,278,282,286,290,294,298,302,306,310,314,318,322,108,76,170,172,174,176,178,180,182,184,186,188,190,192,194,196,198,200,202,204,206,208,210,212,214,216,218,220,222,224,226,230,232,234,236,238,240,242,244,246,248,250,252,254,256,258,260,262,264,266,268,270,272,274,276,278,280,282,284,286,288,290,292,294,296,298,300,302,306,308,310,312,314,316,318,320,322,324,326,328,114,166,168,72,142,146,148,150,152,154,156,158,160,162,164,166,168,170,172,174,176,178,180,182,184,186,188,190,192,194,196,198,200,202,204,206,208,210,212,214,218,220,222,224,226,228,230,232,234,236,238,240,242,244,246,248,250,252,254,256,258,260,262,264,266,268,270,272,274,276,278,280,282,286,290,294,298,302,306,310,314,318,322,326,330,108,72,146,148,150,152,154,156,158,160,162,164,166,168,170,172,174,176,178,180,182,184,186,188,190,192,194,196,198,200,202,204,206,208,210,212,214,218,220,222,224,226,228,230,232,234,236,238,240,242,244,246,248,250,252,254,256,258,260,262,264,266,268,270,272,274,276,278,280,282,284,286,290,294,298,302,306,310,314,318,322,326,330,334,108,76,174,176,178,180,182,184,186,188,190,192,194,196,198,200,202,204,206,208,210,212,214,216,218,220,222,224,226,230,232,234,236,238,240,242,244,246,248,250,252,254,256,258,260,262,264,266,268,270,272,274,276,278,280,282,284,286,288,290,292,294,296,298,300,302,306,308,310,312,314,316,318,320,322,324,326,328,330,332,334,336,338,340,114,172,72,148,150,152,154,156,158,160,162,164,166,168,170,172,174,176,178,180,182,184,186,188,190,192,194,196,198,200,202,204,206,208,210,212,214,218,220,222,224,226,228,230,232,234,236,238,240,242,244,246,248,250,252,254,256,258,260,262,264,266,268,270,272,274,276,278,280,282,284,286,290,292,294,298,302,306,310,314,318,322,326,330,334,338,342,108,72,150,152,154,156,158,160,162,164,166,168,170,172,174,176,178,180,182,184,186,188,190,192,194,196,198,200,202,204,206,208,210,212,214,218,220,222,224,226,228,230,232,234,236,238,240,242,244,246,248,250,252,254,256,258,260,262,264,266,268,270,272,274,276,278,280,282,284,286,290,292,294,296,298,302,306,310,314,318,322,326,330,334,338,342,346,108,72,152,154,156,158,160,162,164,166,168,170,172,174,176,178,180,182,184,186,188,190,192,194,196,198,200,202,204,206,208,210,212,214,218,220,222,224,226,228,230,232,234,236,238,240,242,244,246,248,250,252,254,256,258,260,262,264,266,268,270,272,274,276,278,280,282,284,286,290,292,294,296,298,300,302,306,310,314,318,322,326,330,334,338,342,346,350,108,80,166,168,170,172,174,176,178,180,182,184,186,188,190,192,194,196,198,200,202,204,206,208,210,212,214,216,218,220,222,224,226,228,230,232,234,236,238,242,244,246,248,250,252,254,256,258,260,262,264,266,268,270,272,274,276,278,280,282,284,286,288,290,292,294,296,298,300,302,304,306,308,310,312,314,316,318,322,324,326,328,330,334,338,342,346,350,354,120,72,154,156,158,160,162,164,166,168,170,172,174,176,178,180,182,184,186,188,190,192,194,196,198,200,202,204,206,208,210,212,214,218,220,222,224,226,228,230,232,234,236,238,240,242,244,246,248,250,252,254,256,258,260,262,264,266,268,270,272,274,276,278,280,282,284,286,290,292,294,296,298,300,302,304,306,310,314,318,322,326,330,334,338,342,346,350,354,358,108,72,156,158,160,162,164,166,168,170,172,174,176,178,180,182,184,186,188,190,192,194,196,198,200,202,204,206,208,210,212,214,218,220,222,224,226,228,230,232,234,236,238,240,242,244,246,248,250,252,254,256,258,260,262,264,266,268,270,272,274,276,278,280,282,284,286,290,292,294,296,298,300,302,304,306,308,310,314,318,322,326,330,334,338,342,346,350,354,358,362,108,72,158,160,162,164,166,168,170,172,174,176,178,180,182,184,186,188,190,192,194,196,198,200,202,204,206,208,210,212,214,218,220,222,224,226,228,230,232,234,236,238,240,242,244,246,248,250,252,254,256,258,260,262,264,266,268,270,272,274,276,278,280,282,284,286,290,292,294,296,298,300,302,304,306,308,310,312,314,318,322,326,330,334,338,342,346,350,354,358,362,366,108,80,174,176,178,180,182,184,186,188,190,192,194,196,198,200,202,204,206,208,210,212,214,216,218,220,222,224,226,228,230,232,234,236,238,242,244,246,248,250,252,254,256,258,260,262,264,266,268,270,272,274,276,278,280,282,284,286,288,290,292,294,296,298,300,302,304,306,308,310,312,314,316,318,322,324,326,328,330,332,334,336,338,340,342,344,346,350,354,358,362,366,370,120,72,160,162,164,166,168,170,172,174,176,178,180,182,184,186,188,190,192,194,196,198,200,202,204,206,208,210,212,214,218,220,222,224,226,228,230,232,234,236,238,240,242,244,246,248,250,252,254,256,258,260,262,264,266,268,270,272,274,276,278,280,282,284,286,290,292,294,296,298,300,302,304,306,308,310,312,314,316,318,322,326,330,334,338,342,346,350,354,358,362,366,370,374,108,72,162,164,166,168,170,172,174,176,178,180,182,184,186,188,190,192,194,196,198,200,202,204,206,208,210,212,214,218,220,222,224,226,228,230,232,234,236,238,240,242,244,246,248,250,252,254,256,258,260,262,264,266,268,270,272,274,276,278,280,282,284,286,290,292,294,296,298,300,302,304,306,308,310,312,314,316,318,320,322,326,330,334,338,342,346,350,354,358,362,366,370,374,378,108,80,178,180,182,184,186,188,190,192,194,196,198,200,202,204,206,208,210,212,214,216,218,220,222,224,226,228,230,232,234,236,238,242,244,246,248,250,252,254,256,258,260,262,264,266,268,270,272,274,276,278,280,282,284,286,288,290,292,294,296,298,300,302,304,306,308,310,312,314,316,318,322,324,326,328,330,332,334,336,338,340,342,344,346,348,350,352,354,358,362,366,370,374,378,382,120,80,180,182,184,186,188,190,192,194,196,198,200,202,204,206,208,210,212,214,216,218,220,222,224,226,228,230,232,234,236,238,242,244,246,248,250,252,254,256,258,260,262,264,266,268,270,272,274,276,278,280,282,284,286,288,290,292,294,296,298,300,302,304,306,308,310,312,314,316,318,322,324,326,328,330,332,334,336,338,340,342,344,346,348,350,352,354,356,358,362,366,370,374,378,382,386,120,88,196,198,200,202,204,206,208,210,212,214,216,218,220,222,224,226,228,230,232,234,236,238,240,242,244,246,248,250,252,254,256,258,260,262,266,268,270,272,274,276,278,280,282,284,286,288,290,292,294,296,298,300,302,304,306,308,310,312,314,316,318,320,322,324,326,328,330,332,334,336,338,340,342,344,346,348,350,354,356,358,360,362,364,366,368,370,372,374,376,378,380,382,384,386,388,390,132,88,198,200,202,204,206,208,210,212,214,216,218,220,222,224,226,228,230,232,234,236,238,240,242,244,246,248,250,252,254,256,258,260,262,266,268,270,272,274,276,278,280,282,284,286,288,290,292,294,296,298,300,302,304,306,308,310,312,314,316,318,320,322,324,326,328,330,332,334,336,338,340,342,344,346,348,350,354,356,358,360,362,364,366,368,370,372,374,376,378,380,382,384,386,388,390,392,394,132,92,206,208,210,212,214,216,218,220,222,224,226,228,230,232,234,236,238,240,242,244,246,248,250,252,254,256,258,260,262,264,266,268,270,272,274,278,280,282,284,286,288,290,292,294,296,298,300,302,304,306,308,310,312,314,316,318,320,322,324,326,328,330,332,334,336,338,340,342,344,346,348,350,352,354,356,358,360,362,364,366,370,372,374,376,378,380,382,384,386,388,390,392,394,396,398,400,138,202,204
};
int main()
{
    #ifdef DEBUG
        freopen("input.txt","r",stdin);
        freopen("output.txt","w",stdout);
    #endif
    int t;
    cin >> t;
   while(t--){
       int n;
       cin>>n;
       int pos = 0;
       for(int i = 1;i<n;++i)
        for(int j = 1; j <= i;++j)
            ++pos;
       for(int i = 1; i <= n; ++i){
           cout << table[pos] << " ";
           ++pos;
       }
       cout << endl;
    }
    return 0;
}