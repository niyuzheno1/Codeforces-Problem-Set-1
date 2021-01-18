int lsb(int x){
    return x & (-x);
}
using namespace std;
typedef int ll;
class FenwickTree{
public:
    ll * B; 
    int n;
    FenwickTree(int n){
        this->n = n;
        this->B = new ll[n+3];
        for(int i = 0; i <= n+1; ++i)
            this->B[i] = 0;
    }
    ll getsum(int index){
        ll sum = 0;
        index = index + 1;
        while(index > 0){
            sum = (this->B[index] + sum);
            index -= lsb(index);
        }
        return sum;
    }
    void update(int index, ll val){
        index = index + 1;
        while(index <= n){
            this->B[index] =  (this->B[index] + val ) ;
            index += lsb(index);
        }
    }

};