template <class keyType>
class node  
{  
public: 
    keyType key;  
    node *left, *right, *parent;
    node<keyType>(keyType & a){
        this->key = key;  
        this->left = this->right = this->parent = NULL;  
    }
    node<keyType>(keyType a){
        this->key = key;  
        this->left = this->right = this->parent = NULL;  
    }
    node<keyType>(node * left, keyType & a, node * right){
        this->key = key;  
        this->parent = NULL;
        this->left = left;
        this->right = right;
        if(this->left != nullptr)
            this->left->parent = this;
        if(this->right != nullptr)
            this->right->parent = this;  
    }
};  
