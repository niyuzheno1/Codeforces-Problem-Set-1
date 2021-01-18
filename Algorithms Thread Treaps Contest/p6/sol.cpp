#include <iostream>
#include <vector>
#include <string>

using namespace std;

class atom{
public:
    long long key;
    int size;
    long long sum;
    atom(int x){
        this->sum = x;
        this->size = 1;
        this->key = x;
    }
    atom(){
        this->sum = 0;
        this->size = 1;
        this->key = 0;
    }
    atom & operator =(atom & x){
        this->sum = x.key;
        this->key = x.key;
        this->size = x.size;
        return * this;
    }
};


template <class keyType>
class xnode  
{  
public: 
    keyType key;  
    xnode *left, *right, *parent;
    xnode() : key(), left(nullptr), right(nullptr), parent(nullptr){

    }
    xnode (keyType key){
        this->key = key;
        this->left = this->right = this->parent = nullptr;  
    }
    xnode(xnode * left, keyType  key, xnode * right){
        this->key = key;
        this->parent = nullptr;
        this->left = left;
        this->right = right;
        if(this->left != nullptr)
            this->left->parent = this;
        if(this->right != nullptr)
            this->right->parent = this;  
    }
    void passdown(){

    }
    void update(){
        int size = 1;
        long long sum = this->key.key;
        if(this->left != nullptr){
            size += this->left->key.size;
            sum += this->left->key.sum;
        }
        if(this->right != nullptr){
            size += this->right->key.size;
            sum += this->right->key.sum;
        }
        this->key.sum = sum;
        this->key.size = size;
    }
};  

typedef xnode<atom> node;

#define MAXN 500000

node * trn[MAXN];

class SplayTree{
public:
    node * root;
    SplayTree(){
        root = nullptr;
    }
    node *rightRotate(node *x)  
    {  
        node *y = x->left;
        if(x->parent != nullptr)
            x->parent->passdown();
        x->passdown(); 
        y->passdown();
        x->left = y->right;
        if(y->right != nullptr){
            y->right->parent = x;
        }
        
        y->parent = x->parent;
        if(x->parent == nullptr)
            this->root = y;
        else if (x == x->parent->right)
            x->parent->right = y;
        else
            x->parent->left = y;
        y->right = x;
        x->parent = y;  
        x->update();
        y->update();
        if(y->parent != nullptr)
            y->parent->update();
        return y;  
    }  

    node *leftRotate(node *x)  
    {  
        node *y = x->right;
        if(x->parent != nullptr)
            x->parent->passdown();
        x->passdown(); 
        y->passdown();  
        x->right = y->left;
        if(y->left != nullptr){
            y->left->parent = x;
        }
        y->parent = x->parent;
        if(x->parent == nullptr)
            this->root = y;
        else if (x == x->parent->left)
            x->parent->left = y;
        else
            x->parent->right = y;
        y->left = x;
        x->parent = y;  
        x->update();
        y->update();
        if(y->parent != nullptr)
            y->parent->update();
        return y;  
    }  
    void splay(node * x) {
            while (x->parent) {
                if (!x->parent->parent) {
                    if (x == x->parent->left) {
                        // zig rotation
                        rightRotate(x->parent);
                    } else {
                        // zag rotation
                        leftRotate(x->parent);
                    }
                } else if (x == x->parent->left && x->parent == x->parent->parent->left) {
                    // zig-zig rotation
                    rightRotate(x->parent->parent);
                    rightRotate(x->parent);
                } else if (x == x->parent->right && x->parent == x->parent->parent->right) {
                    // zag-zag rotation
                    leftRotate(x->parent->parent);
                    leftRotate(x->parent);
                } else if (x == x->parent->right && x->parent == x->parent->parent->left) {
                    // zig-zag rotation
                    leftRotate(x->parent);
                    rightRotate(x->parent);
                } else {
                    // zag-zig rotation
                    rightRotate(x->parent);
                    leftRotate(x->parent);
                }
            }
    }
    node* search(node* node, int key) {
            int lsize = 0;
            if(node != nullptr && node->left != nullptr)
                lsize = node->left->key.size;
            if (node == nullptr || key == lsize + 1) {
                return node;
            }

            if (key <= lsize) {
                return search(node->left, key);
            } 
            
            return search(node->right, key-lsize-1);
    }
    node * searchTree(int k) {
            node * x = search(this->root, k);
            if (x) {
                splay(x);
            }
            return x;
    }

    
};

SplayTree base;

int n;

node * getroot(node * x){
    while(x->parent != nullptr)
        x = x->parent;
    return x;
}

int main()
{
    #ifndef ONLINE_JUDGE
        freopen("input.txt","r",stdin);
        freopen("output.txt","w",stdout);
    #endif
    int n ;
    cin >> n;
    for(int i = 1; i<=n; ++i){
        int opn, y, z;
        cin >> opn;
        if(opn == 1){
            
            cin >> y;
            trn[i] = new node(atom(y));
        }
        else if(opn == 4){
            cin>>y;
            node * root1 = getroot(trn[y]);
            cout << root1->key.sum << endl;
        }else if(opn == 3){
            cin>>y>>z;
            node * root1 = getroot(trn[y]);
            base.root = root1;
            node * x = base.searchTree(z+1);
            if(x != nullptr)
            {
                if( base.root->left != nullptr)
                    base.root->left->parent = nullptr;
                base.root->left = nullptr;
                base.root->update();
            }
        }else if(opn == 2){
            cin>>y>>z;
            node * root1 = getroot(trn[y]);
            node * root2 = getroot(trn[z]);
            if(root1 == root2) continue;
            base.root = root2;
            base.searchTree(1);
            base.root->left = root1;
            root1->parent = base.root;
            base.root->update();
        }
    }
    return 0;
}