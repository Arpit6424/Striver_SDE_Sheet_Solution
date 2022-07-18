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
    
//     pair<int,int> solve(TreeNode* root,int dia , int height){
        
//         if(!root)return {0,0};
//         if(!root->left && !root->right)return {0,1};
        
//         //pair<dia,height>
//         pair<int,int> left = solve(root->left,dia,height);
//         pair<int,int> right = solve(root->right,dia,height);
        
//         int maxDia = max({left.first,right.first,left.second+right.second});
//         int maxHeight = max(left.second,right.second)+1;
        
//         return {maxDia,maxHeight};
//     }
// public:
//     int diameterOfBinaryTree(TreeNode* root) {
        
//         return solve(root,0,0).first;
        
//     }
// };










class Solution {
    
    int height(TreeNode* root,int& dia ){
        
        if(!root)return 0;      
        int left = height(root->left,dia);
        int right = height(root->right,dia);
        
        dia = max(dia,left+right);        
        return max(left,right)+1;
        
    }
public:
    int diameterOfBinaryTree(TreeNode* root) {
        
        int dia = 0;
        height(root,dia);
        return dia;
        
    }
};