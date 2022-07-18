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
    
    TreeNode* construct(vector<int>& inorder,int inSt,int inEnd,
                        vector<int>& postorder,int postSt,int postEnd,unordered_map<int,int>& mp){
        
              
        if(inSt > inEnd || postSt > postEnd)return NULL;
        
        int val = postorder[postEnd];
        TreeNode* root = new TreeNode(val);
        
        int nElem = mp[val] - inSt;
        
        root->left  =  construct(inorder,inSt,mp[val]-1,postorder,postSt,postSt+nElem-1,mp);
        root->right =  construct(inorder,mp[val]+1,inEnd,postorder,postSt +nElem,postEnd-1,mp);
        
        return root;
        
    }
    
public:
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {        
        
        int inEnd  = inorder.size()-1;
        int postEnd = postorder.size()-1;
        
        unordered_map<int,int> mp;
        for(int i=0;i<=inEnd;i++)
            mp[inorder[i]] = i;
        
        return construct(inorder,0,inEnd, postorder,0,postEnd,mp);
        
        
        
    }
};