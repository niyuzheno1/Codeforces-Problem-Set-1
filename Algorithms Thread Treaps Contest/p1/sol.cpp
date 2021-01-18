#include <iostream>
#include <vector>
#include <string>
#include <assert.h>     /* assert */

using namespace std;
/*
Find $$x$$
 such that both of the condition holds,
$$a_{i}+x < b_i$$

and $$b_i + x < \text{len}$$

$$x < b_i - a_i$$

$$x < min \{\text{len} - b_i , b_i - a_i\}$$


Now we want to find the position $a_i+x+1$ from our splay ($O(\log n)$)

For the left subtree, we will find $a_i -1 $ and splay it to the left child of the root
For the right subtree, we will find $b_i +x + 1$ and splay it to the right child of the root and we will cut the right subtree of the left child of the root and cut the left subtree of right child of the root and swap them.

There are some boundary condition to consider, for example, we have the root which is $a_i + x + 1$ equal $b_i$, then we will swap the root with the left child's right subtree's left most child and then splay it to the right subtree's root and do the cutting.

*/

class atom{
public:
    int key;
    int size;
    atom(int x){
        this->size = 1;
        this->key = x;
    }
    atom(){
        this->size = 1;
        this->key = 0;
    }
    bool operator <(int x){
        return this->size < x;
    }
    
    bool operator >(int x){
        return this->size > x;
    }
    
    bool operator <=(int x){
        return this->size < x;
    }
    
    bool operator >=(int x){
        return this->size > x;
    }
    
    bool operator ==(int x){
        return this->size == x;
    }
    bool operator <(atom & x){
        return this->size < x.size;
    }
    
    bool operator >(atom & x){
        return this->size > x.size;
    }
    
    bool operator <=(atom & x){
        return this->size < x.size;
    }
    
    bool operator >=(atom & x){
        return this->size > x.size;
    }
    
    bool operator ==(atom & x){
        return this->size == x.size;
    }
    atom & operator =(atom & x){
        this->key = x.key;
        this->size = x.size;
        return * this;
    }
};


bool operator <(int x, atom y){
    return  x < y.size;
}

bool operator >(int x, atom y){
    return   x > y.size;
}

bool operator <=(int x, atom y){
    return x <= y.size;
}

bool operator >=(int x, atom y){
    return x >= y.size;
}

bool operator ==(int x, atom y){
    return y.size == x;
}

template <class keyType>
class xnode  
{  
public: 
    keyType key;  
    xnode *left, *right, *parent;
    
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
        if(this->left != nullptr)
            size += this->left->key.size;
        if(this->right != nullptr)
            size += this->right->key.size;
        this->key.size = size;
    }
};  

typedef xnode<atom> node;
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

    void insert(int key) {
            node* inode = new node(atom(key));
            node* y = nullptr;
            node* x = this->root;

            while (x != nullptr) {
                y = x;
                if (inode->key < x->key) {
                    x = x->left;
                } else {
                    x = x->right;
                }
            }

            inode->parent = y;
            if (y == nullptr) {
                this->root = inode;
            } else if (inode->key < y->key) {
                y->left = inode;
            } else {
                y->right = inode;
            }
            splay(inode);
    }
    node * build(int l, int r){
        if(l > r)
            return nullptr;
        if(l == r)
            return new node(l);
        int mid = (l+r)>>1;
        node * le = this->build(l, mid-1);
        node * re = this->build(mid+1,r);
        node * mi  = new node(le, atom(mid), re);
        mi->update();
        return mi;
    }
    
    void print(vector<int> & ans, node * tr, int n){
        if(tr == nullptr)
            return;
        print(ans, tr->left, n);
        if(tr->key.key <= n && tr->key.key > 0 )
            ans.push_back(tr->key.key);
        print(ans, tr->right, n);
    }
    void show(int n){
         vector<int> tmp;
         print(tmp, this->root, n);
         cout << tmp[0];
         for(int i = 1; i< tmp.size(); ++i)
            cout << " " << tmp[i] ;
        cout << endl;
    }
};
SplayTree base; 
SplayTree base2;
SplayTree base3;
SplayTree base4;

int main()
{
    #ifndef ONLINE_JUDGE
        freopen("input.txt","r",stdin);
        freopen("output.txt","w",stdout);
    #endif
    int n ;
    cin>> n;
    base.root = base.build(0, n + 1);
    for(int i = 0; i < n; ++i){
        int a,b;
        cin >> a >> b;
        int de1 = b-a-1,de2 = n-b; 
        if(a >= b){
       //     goto endloop;
       continue;
        }
        int x = min(de1,de2);
        base.searchTree(a+x+2);
        base2.root = base.root->left;
        if(base2.root != nullptr)
            base2.root->parent = nullptr;
        base2.searchTree(a);
        base3.root = base.root->right;
        if(base3.root != nullptr)
            base3.root->parent = nullptr;
        base3.searchTree((b-(a+x+1))+x+1);
        if((b-(a+x+2)) < 0 || de1 == de2){        
            base4.root = nullptr;
            if(base2.root != nullptr)
                base4.root = base2.root->right;
            if(base4.root != nullptr)
                base4.root->parent = nullptr;
            base4.searchTree(1);
            assert(base4.root != nullptr);
            assert(base3.root != nullptr);
            int size1=0,size2=0;
            if(base4.root->right != nullptr)
                size1 = base4.root->right->key.size; 
            if(base3.root->left != nullptr)
                size2 = base3.root->left->key.size;
            assert(size1 == size2);
            swap(base.root->key.key, base4.root->key.key);
            node * rightoftheleft = base4.root->right;
            node * leftoftheright = base3.root->left;
            if(rightoftheleft != nullptr)
                rightoftheleft->parent = base3.root;
            if(leftoftheright != nullptr)
                leftoftheright->parent = base4.root;
            base4.root->right = leftoftheright;
            base3.root->left = rightoftheleft;        
            base4.root->parent = base2.root;
            base2.root->right = base4.root;
        }else if((b-(a+x+2)) > 0)
        {
            base4.root = nullptr;
            if(base3.root != nullptr)
                base4.root = base3.root->left;
            if(base4.root != nullptr)
                base4.root->parent = nullptr;
            base4.searchTree((b-(a+x+2)));
            node * rightoftheleft = base2.root->right;
            node * leftoftheright = base4.root->right;
            assert(rightoftheleft->key.size == leftoftheright->key.size);
            if(rightoftheleft != nullptr)
                rightoftheleft->parent = base4.root;
            if(leftoftheright != nullptr)
                leftoftheright->parent = base2.root;
            base2.root->right = leftoftheright;
            base4.root->right = rightoftheleft;
            base4.root->parent = base3.root;
            base3.root->left = base4.root;
        }
        else{
            node * rightoftheleft = base2.root->right;
            node * leftoftheright = base3.root->left;
            if(rightoftheleft != nullptr)
                rightoftheleft->parent = base3.root;
            if(leftoftheright != nullptr)
                leftoftheright->parent = base2.root;
            base2.root->right = leftoftheright;
            base3.root->left = rightoftheleft;
        }
        base3.root->parent = base.root;
        base.root->right = base3.root;
        base2.root->parent = base.root;
        base.root->left = base2.root;
 //endloop:
    ;
    //base.show(n); 
    }
    base.show(n); 
    return 0;
}