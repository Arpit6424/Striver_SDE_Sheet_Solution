/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
 
 
 bool helper(TreeNode* root, int B,vector<int>& path){
     
     if(root==NULL)return false;
     if(root->val == B){
         path.push_back(root->val);
         return true;
     }
     
     path.push_back(root->val);
     if(helper(root->left,B,path))return true;;
     path.pop_back();
     
     path.push_back(root->val);
     if(helper(root->right,B,path))return true;
     path.pop_back();
     
     return false;
     
 }
 
vector<int> Solution::solve(TreeNode* A, int B) {
    
    
    vector<int> path;
    
    helper(A,B,path);
    return path;
}
