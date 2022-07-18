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
    
//     void inorderTraversal(TreeNode* root,vector<int>& inorder){
        
//         if(!root)return ;
        
//         inorderTraversal(root->left,inorder);
//         inorder.push_back(root->val);
//         inorderTraversal(root->right,inorder);
//     }
// public:
//     bool findTarget(TreeNode* root, int k) {
        
//         vector<int> inorder;        
//         inorderTraversal(root,inorder);
        
//         int i=0,j=inorder.size()-1;
        
//         while(i<j){
            
//             if(inorder[i]+inorder[j] == k)return true;
            
//             if(inorder[i]+inorder[j] > k)j--;
//             else i++;
//         }
//         return false;
        
//     }
// };


class BSTIterator{
    private: stack<TreeNode*> st;
    //reverse==true == back se next(inorder traversal in reverse order)
    //reverser==false == aage se next;(inorder traversal)
    bool reverse;
    
    public:
    BSTIterator(TreeNode* root, bool isReverse){
        reverse = isReverse;
        pushAll(root);
    }
    
    public:
    int next(){
        if(st.empty())return -1;
        TreeNode* node = st.top();
        st.pop(); 
        if(!reverse) pushAll(node->right);
        else pushAll(node->left);
         
        return node->val;
    }
    
    void pushAll(TreeNode* root){
        
        while(root){
            st.push(root);
            if(reverse)root = root->right;
            else root = root->left;
        }
    }
    
};





class Solution {
    

public:
    bool findTarget(TreeNode* root, int k) {
        if(!root)return false;
        
        BSTIterator l(root,false);//inorder Traversal
        BSTIterator r(root,true);//inorder Traversal (reverse order);
        
        int i = l.next();
        int j = r.next();
          
        while(i<j){            
            if(i+j==k)return true;
            if(i+j > k)j = r.next();
            else i = l.next();
        }
        return false;              
    }
};

















