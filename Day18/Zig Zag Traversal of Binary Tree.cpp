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
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        if(!root)return {};
        
        queue<TreeNode*> q;
        q.push(root);
        vector<vector<int>> ans;
        
        
        bool reverse = false;        
        while(!q.empty()){
            
            int size = q.size();
            vector<int> level(size);
            
            for(int i=0;i<size;i++){
                
                TreeNode* cur = q.front();
                q.pop();
                
                int ind = reverse ?size-1-i : i ;
                level[ind] = cur->val;
                
                if(cur->left)
                    q.push(cur->left);
                if(cur->right)
                    q.push(cur->right);
               
            }
             reverse = !reverse;
            ans.push_back(level);
        }
        return ans;
    }
};