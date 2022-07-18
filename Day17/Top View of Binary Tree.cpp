
/*
struct Node
{
    int data;
    Node* left;
    Node* right;
};
*/







class Solution {
    
    
    void solve(Node* root,map<int,pair<int,int>>& mp,int hd,int level){
        if(root==NULL)return;
        
        if(mp.find(hd)== mp.end() || mp[hd].first >= level)
         mp[hd] = {level,root->data};

        solve(root->left, mp,hd-1,level+1);
        solve(root->right,mp,hd+1,level+1);
        
    }
    
  public:
    vector <int> topView(Node *root) {
        // Your Code Here
        vector<int> ans;
        // map<hd,pair<level,data>
         map<int,pair<int,int>> mp;
        solve(root,mp,0,0);
        
        for(auto it: mp)ans.push_back(it.second.second);
        return ans;
    }
};











// class Solution
// {
//     public:
//     //Function to return a list of nodes visible from the top view 
//     //from left to right in Binary Tree.
//     vector<int> topView(Node *root)
//     {
//         if(root==NULL)return {};
     
//         vector<int> ans;
//         // map<hd,data>
//          map<int,int> mp;
         
//          queue<pair<Node*,int>> q;
//          q.push({root,0});
         
//          while(!q.empty()){
             
//              int x = q.size();
//              while(x--){
                 
//                  Node* cur = q.front().first;
//                  int hd = q.front().second;
//                  q.pop();
                 
//                  if(mp.find(hd)==mp.end())
//                   mp[hd] = cur->data;
                 
//                  if(cur->left)
//                   q.push({cur->left,hd-1});
                  
//                  if(cur->right)
//                   q.push({cur->right,hd+1});
//              }
//          }
         
//          for(auto it: mp)ans.push_back(it.second);
//          return ans;
//     }

// };

