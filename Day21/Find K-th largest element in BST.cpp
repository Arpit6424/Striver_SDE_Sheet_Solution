// return the Kth largest element in the given BST rooted at 'root'
class Solution
{
    void inorderTraversal(Node* root ,int& k,int& ans){
    
       if(!root)return ;
       inorderTraversal(root->right,k , ans); 
       k--;
       if(k==0)ans = root->data;
       inorderTraversal(root->left,k,ans);
               

    }
    public:
    int kthLargest(Node *root, int K)
    {
        //Your code here
        int ans = -1;
        inorderTraversal(root,K,ans);
        return ans;
    }
};