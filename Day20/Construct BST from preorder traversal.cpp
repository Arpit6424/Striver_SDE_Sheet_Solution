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
    
//     TreeNode* construct(vector<int>& preorder,int preSt,int preEnd,
//                          vector<int>& inorder,int inSt, int inEnd,unordered_map<int,int>& mp){
        
        
//         if(preSt > preEnd || inSt > inEnd)return NULL;
        
//         int val = preorder[preSt];
//         TreeNode* root = new TreeNode(val);
        
//           int ind = mp[val];
//           int nElem = ind - inSt;
    
        
//         root->left = construct(preorder,preSt+1,preSt+nElem,inorder, inSt,mp[val]-1,mp);
//         root->right = construct(preorder,preSt+nElem+1,preEnd,inorder,mp[val]+1,inEnd,mp);
        
//         return root;
//     }
    
// public:
//     TreeNode* bstFromPreorder(vector<int>& preorder) {
        
//         vector<int> inorder = preorder;        
//         sort(inorder.begin(),inorder.end());
        
//         unordered_map<int,int> mp;
//         for(int i=0;i<inorder.size();i++)
//             mp[inorder[i]] = i;
        
//         int preEnd = preorder.size()-1;
//         int inEnd  = inorder.size()-1;
        
//         return construct(preorder,0,preEnd,inorder, 0,inEnd,mp);
        
//     }
// };








class Solution { 
    
    TreeNode* build(vector<int>& preorder,int& i,int bound){
        
        if(i==preorder.size() || preorder[i] > bound)return NULL; 
        
        TreeNode* root = new TreeNode(preorder[i++]);        
        root->left  = build(preorder,i,root->val);
        root->right = build(preorder,i,bound);
        return root;
    }
public:
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        
        int i =0;
        return build(preorder,i,INT_MAX);        
    }
};