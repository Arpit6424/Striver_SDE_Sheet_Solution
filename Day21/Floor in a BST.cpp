/************************************************************

    Following is the TreeNode class structure

    template <typename T>
    class TreeNode {
       public:
        T val;
        TreeNode<T> *left;
        TreeNode<T> *right;

        TreeNode(T val) {
            this->val = val;
            left = NULL;
            right = NULL;
        }
    };

************************************************************/

int floorInBST(TreeNode<int> * root, int X)
{
    int floorValue;    
    while(root){        
        if( root->val > X)root = root->left;
        else{
            floorValue = root->val;
            root = root->right;
        }
    }
    return floorValue;
}