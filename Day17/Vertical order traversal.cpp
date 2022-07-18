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
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        
        if(root==NULL)return {};
        //map< hd , map<level,vector>
        map<int, map<int,multiset<int>>> mp;
                            // pair<hd,level>
        queue<pair<TreeNode* ,pair<int,int>>> q;        
        q.push({root,{0,0}});
        
        while(!q.empty()){            
            int size = q.size();
            while(size--){
                
                TreeNode* cur = q.front().first;
                int hd = q.front().second.first;
                int level = q.front().second.second;
                q.pop();
                
                mp[hd][level].insert(cur->val);                
                if(cur->left)
                    q.push({cur->left,{hd-1,level+1}});
                if(cur->right)
                    q.push({cur->right,{hd+1,level+1}});
            }
        }        
        vector<vector<int>> ans;        
        for(auto p : mp){
            vector<int> temp;
            for(auto it : p.second){
                temp.insert(temp.end(),it.second.begin(),it.second.end());
            }
            ans.push_back(temp);
        }
            
                
        return ans;
        
    }
};








