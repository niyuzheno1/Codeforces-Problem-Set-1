#include <iostream>
#include <vector>
#include <string>
#include <cstring>

using namespace std;

string ix;

class atom{
public:
    atom(){
        memset(&lc,0,sizeof(lc));
        memset(&rc,0,sizeof(rc));
        reverse = 0;
        intervalLength = 0;
        maxcontin = 0;
        label = -1;
    }
    
    atom(int label){
        memset(&lc,0,sizeof(lc));
        memset(&rc,0,sizeof(rc));
        lc[label] = rc[label] = 1;
        reverse = 0;
        intervalLength = 1;
        maxcontin = 1;
        label = label;
    }
    void apply(){
        if(reverse){
            swap(lc[0],lc[1]);
            swap(rc[0],rc[1]);
            if(label != -1)
                label = label^1;
            reverse = 0;
        }
    }
    int maxcontin, label;
    int reverse, intervalLength; 
    int lc[2],rc[2];
};

class node{
public:
    atom d;
    node * left,*right;
    node() : d(), left(nullptr), right(nullptr){
        
    }
    node(node *left, node * right) : d() {
        this->left = left;
        this->right = right;
        this->update();
    }
    node(int label) : d(label) , left(nullptr), right(nullptr) {
     
    }
    node(node *left, node * right, int label) : d(label) {
        this->left = left;
        this->right = right;

    }
    void passdown(){
        int x = this->d.reverse;
        if(this->left != nullptr)
            this->left->d.reverse ^= x;
        if(this->right != nullptr)
            this->right->d.reverse ^= x;
        this->d.apply();
    }
    void update(){
        this->d.maxcontin = 0;
        vector<int> candidates;
        for(int i = 0; i < 2; ++i){
            atom latom;
            atom ratom;
            latom.intervalLength = -1;
            ratom.intervalLength = -1;
            if(this->left != nullptr){
                this->left->passdown();
                latom.lc[i] = this->left->d.lc[i];
                latom.rc[i] = this->left->d.rc[i];
                latom.intervalLength = this->left->d.intervalLength;
                latom.maxcontin = this->left->d.maxcontin;
            }
            if(this->right != nullptr){
                this->right->passdown();
                ratom.lc[i] = this->right->d.lc[i];
                ratom.rc[i] = this->right->d.rc[i];
                ratom.intervalLength = this->right->d.intervalLength;
                ratom.maxcontin = this->right->d.maxcontin;
            }
            if(latom.intervalLength == latom.lc[i])    
                this->d.lc[i] = latom.lc[i] + ratom.lc[i];
            else if(latom.intervalLength == -1)
                this->d.lc[i] = ratom.lc[i];
            else
                this->d.lc[i] = latom.lc[i];
            
            if(ratom.intervalLength == ratom.rc[i])
                this->d.rc[i] = latom.rc[i] + ratom.rc[i];
            else if(ratom.intervalLength == -1)
                this->d.rc[i] = latom.rc[i];
            else
                this->d.rc[i] = ratom.rc[i];
            candidates.push_back(this->d.rc[i]);
            candidates.push_back(this->d.lc[i]);
            candidates.push_back(latom.rc[i] + ratom.lc[i]);
            candidates.push_back(latom.maxcontin);
            candidates.push_back(ratom.maxcontin);
        }
        this->d.maxcontin = candidates[0];
        for(int i = 1; i < candidates.size(); ++i)
            this->d.maxcontin = max(this->d.maxcontin, candidates[i]);
        
    }
};

node * build(int l, int r){
    if(l > r)
        return nullptr;
    if(l == r){
        return new node(ix[l-1]-'0');
    }
    int mid = (l+r)>>1;
    node * nd = new node(build(l,mid), build(mid+1,r));
    nd->d.intervalLength = r-l+1;
    return nd;
}

void reverseInv(node * c,int l, int r, int ll, int rr)
{
    if(l > r)
        return;
    if(l == r){
        if(l == r && ll <= l && r <= rr){
            c->d.reverse ^= 1;
            c->d.apply();
        }
        return;
    }
    c->passdown();
    if(ll <= l && r <= rr){
        c->d.reverse ^= 1;
        c->passdown();
        return;
    }
    int mid = (l+r)>>1;
    if(mid >= ll)
        reverseInv(c->left, l, mid, ll, rr);
    if(mid+1 <= rr)
        reverseInv(c->right, mid+1, r, ll, rr);
    c->update();
}

node * root;
int main()
{
    #ifndef ONLINE_JUDGE
        freopen("input.txt","r",stdin);
        freopen("output.txt","w",stdout);
    #endif
    int n,q;
    cin >> n >> q;
    cin >> ix;
    root = build(1,n);
    for(int i = 0; i < q; ++i){
        int a,b,c;
        // if(i == 1)
        // __asm int 3;
        cin >> a >> b>>c;
        reverseInv(root,1,n,b,c);
        cout << root->d.maxcontin <<endl;
    }
    return 0;
}