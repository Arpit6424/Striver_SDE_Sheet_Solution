/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        
        if(!root)return "";
        
        queue<TreeNode*> q;
        q.push(root);        
        string s = "";
        
        while(!q.empty()){
            TreeNode* topNode = q.front();
            q.pop();
            
            if(topNode==NULL)s.append("#,");
            else s.append(to_string(topNode->val) +',');
            
            if(topNode){
                q.push(topNode->left);
                q.push(topNode->right);
            }
        }
        return s;
        
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        if(data.length()==0)return NULL;
        
        stringstream s(data);
        string str;
        getline(s,str,',');
        
        TreeNode* root = new TreeNode(stoi(str));
        queue<TreeNode*> q;
        q.push(root);
        
        while(!q.empty()){
            TreeNode* topNode = q.front();
            q.pop();
            
            getline(s,str,',');
            if(str=="#")topNode->left = NULL;
            else{
                TreeNode* newNode = new TreeNode(stoi(str));
                topNode->left = newNode;
                q.push(newNode);
            }
            
            getline(s,str,',');
            if(str=="#")topNode->right = NULL;
            else{
                TreeNode* newNode = new TreeNode(stoi(str));
                topNode->right = newNode;
                q.push(newNode);
            }
        }
        return root;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));