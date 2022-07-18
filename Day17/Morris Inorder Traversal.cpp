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
    
//     void solve(TreeNode* root, vector<int> &ans){
        
//         if(root==NULL)return ;
        
//         solve(root->left,ans);    
//         ans.push_back(root->val);
//         solve(root->right,ans);
//     }
    
    
// public:
//     vector<int> inorderTraversal(TreeNode* root) {
        
//         vector<int> ans;
//         solve(root,ans);
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
//     vector<int> inorderTraversal(TreeNode* root) {
        
        
//         stack<TreeNode*> st;
//         vector<int> ans;
        
//         while(true){
            
//             if(root){
//                 st.push(root);
//                 root = root->left;
//             }
//             else{
//                 if(st.empty())break;
//                 root = st.top();
//                 st.pop();
//                 ans.push_back(root->val);
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
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> inorder;
        
        TreeNode* curr = root;
        
        while(curr){
            
            if(curr->left == NULL){
                inorder.push_back(curr->val);
                curr = curr->right;
            }
            else{
                
                TreeNode* prev = curr->left;
                while(prev->right && prev->right != curr)
                    prev = prev->right;
                
                if(prev->right == NULL){
                    prev->right = curr;
                    curr = curr->left;
                }
                else{
                    prev->right = NULL;
                    inorder.push_back(curr->val);
                    curr = curr->right;
                }
            }
        }
        return inorder;
        
    }
};


/*******************************************************************/
/****************************************************************/







