class Solution {
  public:
    // Function to return Breadth First Traversal of given graph.
    vector<int> bfsOfGraph(int V, vector<int> adj[]) {
        // Code here
        vector<int> ans;
        queue<int> q;
        vector<bool> vis(V,false);
        q.push(0);
        vis[0] = true;
        
        while(!q.empty()){
            int topNode = q.front();
            q.pop();
            ans.push_back(topNode);
            
            for(auto it: adj[topNode]){
                if(!vis[it])
                  q.push(it);
                  vis[it] = true;
            }
        }
        return ans;
    }
};