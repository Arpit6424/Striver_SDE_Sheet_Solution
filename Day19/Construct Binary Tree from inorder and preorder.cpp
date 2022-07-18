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
    
    
    TreeNode* construct(vector<int>& preorder,int preSt,int preEnd,
                         vector<int>& inorder,int inSt, int inEnd,unordered_map<int,int>& mp){
        
        
        if(preSt > preEnd || inSt > inEnd)return NULL;
        
        int val = preorder[preSt];
        TreeNode* root = new TreeNode(val);
        
          int ind = mp[val];
          int nElem = ind - inSt;
    
        
        root->left = construct(preorder,preSt+1,preSt+nElem,inorder, inSt,mp[val]-1,mp);
        root->right = construct(preorder,preSt+nElem+1,preEnd,inorder,mp[val]+1,inEnd,mp);
        
        return root;
    }
    
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        
        int preEnd = preorder.size();
        int inEnd = inorder.size();
        
        unordered_map<int,int> mp;
        for(int i=0;i<inEnd;i++){
            
            mp[inorder[i]] = i;
        }
        return construct(preorder,0,preEnd-1,inorder,0,inEnd-1,mp );
        
    }
};