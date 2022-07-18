/************************************************************

    Following is the Binary Tree node structure:

    class BinaryTreeNode
    {
    public :
        T data;
        BinaryTreeNode<T> *left;
        BinaryTreeNode<T> *right;

        BinaryTreeNode(T data) {
            this -> data = data;
            left = NULL;
            right = NULL;
        }
    };


************************************************************/
#include<bits/stdc++.h>
vector<vector<int>> getTreeTraversal(BinaryTreeNode<int> *root){
    // Write your code here.
    if(root==NULL)return {};
    stack<pair<BinaryTreeNode<int>*,int>> st;
    vector<int> inorder, preorder,postorder;
    st.push({root,1});
    
    while(!st.empty()){
        auto it = st.top();
        st.pop();
        
        if(it.second==1){
            preorder.push_back(it.first->data);
            it.second++;
            st.push(it);
            if(it.first->left)
                st.push({it.first->left,1});
        }
        
        else if(it.second==2){
            inorder.push_back(it.first->data);
            it.second++;
            st.push(it);
            if(it.first->right)
                st.push({it.first->right,1});
        }
        else{
            postorder.push_back(it.first->data);
        }
        
    }
    return {{inorder},{preorder},{postorder}};
    
}