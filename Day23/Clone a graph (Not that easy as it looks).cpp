/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
// */







//Using Dfs traversal



// class Solution {
    
//     void dfs(Node* node , Node* copy,vector<Node*>& vis){
        
//         vis[copy->val] = copy;        
//         for(auto child : node->neighbors){            
//             if(vis[child->val]==NULL){                
//                 Node* newNode = new Node(child->val);
//                 copy->neighbors.push_back(newNode);
//                 dfs(child ,newNode,vis);
//             }
//             else{
//                 copy->neighbors.push_back(vis[child->val]);
//             }
//         }
//     }
    
    
// public:
//     Node* cloneGraph(Node* node) {
        
//         if(!node)return NULL;
        
//         vector<Node*> vis(101,NULL);        
//         Node* copy = new Node(node->val);
        
//         dfs(node,copy,vis);
//         return copy;                    
//     }
// };





//Using bfs traversal


class Solution {
public:
    Node* cloneGraph(Node* node) {
        
        if(!node)return NULL;
        
        Node* copy = new Node(node->val);        
        vector<Node*> vis(101,NULL);
        
        vis[copy->val] = copy;
        
        queue<pair<Node*,Node*>> q;
        q.push({copy,node});
        
        while(!q.empty()){
            
            Node* duplicateNode = q.front().first;
            Node* node = q.front().second;
            q.pop();
            
            for(auto child : node->neighbors){
                
                if(vis[child->val]==NULL){
                    Node* newNode = new Node(child->val);
                    duplicateNode->neighbors.push_back(newNode);
                    q.push({newNode,child});
                    
                    vis[newNode->val] = newNode;
                    
                }
                else{
                    duplicateNode->neighbors.push_back(vis[child->val]);
                }
            }
        }
        return copy;
                   
    }
};


















