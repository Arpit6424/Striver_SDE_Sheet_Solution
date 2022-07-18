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


/*******************************************************************/
/****************************************************************/
// Approach-1 recursive
// Time compplexity O(n);
// Space complexity O(n);

// class Solution {
    
//     void solve(TreeNode* root, vector<int>& ans){
//         if(root==NULL)return;
        
//         ans.push_back(root->val);
//         solve(root->left,ans);
//         solve(root->right,ans);
//     }
    
// public:
//     vector<int> preorderTraversal(TreeNode* root) {
        
//         vector<int> ans;
//         solve(root, ans);
//         return ans;
        
//     }
// };



/*******************************************************************/
/****************************************************************/

// Approach-2 iterative
// Time compplexity O(n);
// Space complexity O(n);

// class Solution {    
// public:
//     vector<int> preorderTraversal(TreeNode* root) {        
//         vector<int> ans;
//         stack<TreeNode*> st;        
//         while(true){            
//             if(root){
//                 ans.push_back(root->val);
//                 st.push(root);
//                 root = root->left;
//             }
//             else{                
//                 if(st.empty())break;
//                 root = st.top();
//                 st.pop();
//                 root = root->right;
//             }
//         }
//         return ans;
//     }
// };



/*******************************************************************/
/****************************************************************/

// Approach-2 Morris traversal
// Time compplexity O(2n);
// Space complexity O(1);

class Solution {    
public:
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> preorder;        
        TreeNode* curr = root;
        
        while(curr){
            
            if(curr->left == NULL){
                preorder.push_back(curr->val);
                curr = curr->right;
            }
            else{
                
                TreeNode* prev = curr->left;
                while(prev->right && prev->right != curr)
                    prev = prev->right;
                
                if(prev->right == NULL){
                    prev->right = curr;
                    preorder.push_back(curr->val);
                    curr = curr->left;
                }
                else{
                    prev->right = NULL;
                    curr = curr->right;
                }
            }
        }
        return preorder;
    }
};




