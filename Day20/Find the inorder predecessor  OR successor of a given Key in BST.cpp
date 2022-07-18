void findPreSuc(Node* root, Node*& pre, Node*& suc, int key)
{
    
    Node* cur = root;
    
    while(cur){
        if(key >= cur->key){
             cur = cur->right;
        }
        else{
            suc = cur;
            cur = cur->left;
        }
    }
    
    
   cur = root;
    
    while(cur){
        
        if(key > cur->key){
            pre = cur;
            cur = cur->right;
            
        }
        else{
            cur = cur->left;
        }
    }

// Your code goes here

  

}