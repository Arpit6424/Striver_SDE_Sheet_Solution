
// class Solution {
    
    
//     Node* solve(Node* root){
        
//         if(!root)return root;
        
//         Node* left  = solve(root->left);
//         Node* right = solve(root->right);
        
        
//         root->left = right;
//         root->right = left;
//         return root;
//     }
    
//   public:
//     // Function to convert a binary tree into its mirror tree.
//     void mirror(Node* node) {
//         // code here
//         solve(node);
//     }
// };









class Solution {   
  public:
    // Function to convert a binary tree into its mirror tree.
    void mirror(Node* node) {
        // code here
        if(!node)return ;
        
        Node* temp = node->left;
        
        node->left = node->right;
        node->right = temp;
        
        mirror(node->left);
        mirror(node->right);
    }
};


