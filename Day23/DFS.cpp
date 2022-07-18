// class Solution {
    
//     void dfsTraversal(vector<int> adj[],int node,vector<bool>& vis,vector<int>&ans){
        
//         ans.push_back(node);
//         vis[node] = true;
        
//         for(auto it : adj[node]){
//             if(!vis[it])dfsTraversal(adj,it,vis,ans);
//         }
        
//     }
    
//   public:
//     // Function to return a list containing the DFS traversal of the graph.
//     vector<int> dfsOfGraph(int V, vector<int> adj[]) {
//         // Code here
        
//         vector<bool> vis(V,false);
//         vector<int> ans;
        
//         for(int node=0;node<V;node++)
//             if(!vis[node])dfsTraversal(adj,node,vis,ans);
        
//         return ans;
        
//     }
// };






class Solution {
  public:
    // Function to return a list containing the DFS traversal of the graph.
    vector<int> dfsOfGraph(int V, vector<int> adj[]) {
        
        stack<int> st;
        vector<bool> vis(V,false);
        vector<int> ans;
        
        st.push(0);
        while(!st.empty()){
            int topNode = st.top();
            st.pop();
            
            if(!vis[topNode]){
                vis[topNode] = true;
                ans.push_back(topNode);
            }
            for(int i=adj[topNode].size()-1;i>=0;i--){
                
                if(!vis[adj[topNode][i]])
                    st.push(adj[topNode][i]);
            }
        }
        return ans;
    }
};
