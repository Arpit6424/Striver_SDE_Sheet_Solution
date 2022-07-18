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

class NodeValue{
    public:
    int maxNode,minNode,maxSum;
    public:
    NodeValue(int minNode , int maxNode, int maxSum){
        this->minNode = minNode;//maximum from left side
        this->maxNode = maxNode;//minimum from right side
        this->maxSum = maxSum;
    }
};
class Solution {
    
    int sum =0;
    NodeValue postorderTraversal(TreeNode* root){
        
        if(!root)return NodeValue(INT_MAX,INT_MIN,0);
        
        NodeValue left  = postorderTraversal(root->left);
        NodeValue right = postorderTraversal(root->right);
    
        if(left.maxNode < root->val && root->val < right.minNode){
            sum = max(sum, root->val + left.maxSum + right.maxSum);
            return NodeValue(min(root->val,left.minNode) ,
                             max(root->val, right.maxNode),root->val+left.maxSum+right.maxSum);
        }
        
        return NodeValue(INT_MIN,INT_MAX,max(left.maxSum,right.maxSum));
    }
public:
    int maxSumBST(TreeNode* root) {
        
         postorderTraversal(root);
         return sum;
    }
};