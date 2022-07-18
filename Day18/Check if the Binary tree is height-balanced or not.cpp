/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
// class Solution {
    
//     int solve(TreeNode* root,bool &ans){
        
//         if(!root)return 0;
        
//         int left = solve(root->left,ans);
//         int right = solve(root->right,ans);
        
//         if(abs(left-right)>1)ans = false;
//         return max(left,right)+1;
//     }
    
// public:
//     bool isBalanced(TreeNode* root) {
//         bool ans = true;
//         solve(root,ans);
//         return ans;
        
//     }
// };










class Solution {
    
    int solve(TreeNode* root){
        
        if(!root)return 0;
        
        int left = solve(root->left);        
        if(left == -1)return -1;
        
        int right = solve(root->right);        
        if(right==-1)return -1;
        
        if(abs(left-right)>1)return -1;;
        
        return max(left,right)+1;
    }
    
public:
    bool isBalanced(TreeNode* root) {
   
        return solve(root) != -1;
  
        
    }
};