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
class Solution {
    
    bool check(TreeNode* root,long lbound ,long ubound){
                
        if(!root)return true;
        
        bool left = check(root->left,lbound , root->val);        
        bool right = check(root->right,root->val, ubound);

        return (left && right && lbound < root->val && root->val < ubound );
        
    }
public:
    bool isValidBST(TreeNode* root) {
        
        return check(root, LONG_MIN, LONG_MAX);
        

            
        
    }
};