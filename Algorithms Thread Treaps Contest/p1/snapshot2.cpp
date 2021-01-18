if(de1 == de2){
            base.searchTree(a+x+2);
            base2.root = base.root->left;
            if(base2.root != nullptr)
                base2.root->parent = nullptr;
            base2.searchTree(a);
            base3.root = base.root->right;
            if(base3.root != nullptr)
                base3.root->parent = nullptr;
            base3.searchTree(x+1);
            base4.root = nullptr;
            if(base2.root != nullptr)
                base4.root = base2.root->right;
            if(base4.root != nullptr)
                base4.root->parent = nullptr;
            base4.searchTree(1);
            assert(base4.root != nullptr);
            assert(base3.root != nullptr);
            assert(base4.root->right->key.size == base3.root->left->key.size);

            swap(base.root->key.key, base4.root->key.key);
            node * rightoftheleft = base4.root->right;
            node * leftoftheright = base3.root->left;
            rightoftheleft->parent = base3.root;
            leftoftheright->parent = base4.root;


            base4.root->right = leftoftheright;
            base3.root->left = rightoftheleft;


            base4.root->parent = base2.root;
            base2.root->right = base4.root;
            base3.root->parent = base.root;
            base.root->right = base3.root;
            base2.root->parent = base.root;
            base.root->left = base2.root;