/************************************************************

    Following is the Binary Tree node structure:
    
    template <typename T>
    class TreeNode {
        public :
        T data;
        TreeNode<T> *left;
        TreeNode<T> *right;

        TreeNode(T data) {
            this -> data = data;
            left = NULL;
            right = NULL;
        }

        ~TreeNode() {
            if(left)
                delete left;
            if(right)
                delete right;
        }
    };

************************************************************/

void leftTraversal(TreeNode<int>* root , vector<int>& ans){    
     if(!root ||(!root->left && !root->right))return ;  
     
    ans.push_back(root->data);
    leftTraversal(root->left,ans);
    
    if(root->left==NULL)
        leftTraversal(root->right,ans);
}
void leafTraversal(TreeNode<int>* root , vector<int>& ans){
    if(!root)return ;
    if(!root->left && !root->right){
        ans.push_back(root->data);
        return ;
    }    
    leafTraversal(root->left,ans);
    leafTraversal(root->right,ans);
}

void rightTraversal(TreeNode<int>* root , vector<int>& ans){    
     if(!root ||(!root->left && !root->right))return ;  
     rightTraversal(root->right,ans);
    
    if(root->right==NULL)
        rightTraversal(root->left,ans);
     ans.push_back(root->data);
}
vector<int> traverseBoundary(TreeNode<int>* root){
    // Write your code here.
    if(!root)return {};
    vector<int> ans;
    ans.push_back(root->data);
    if(root->left)
     leftTraversal(root->left,ans);
    
    leafTraversal(root->left,ans);
    leafTraversal(root->right,ans);
    
    if(root->right)
     rightTraversal(root->right, ans);
    return ans;
}












