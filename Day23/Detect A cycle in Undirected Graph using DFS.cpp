#include<bits/stdc++.h>
// bool isCycle(vector<int> adj[],vector<bool> &vis,int node, int parent){    
//     vis[node] = true;    
//     for(auto it :adj[node]){        
//         if(!vis[it]) {
//             if(isCycle(adj,vis,it,node))
//               return true;
//         }
//         else if(it != parent)return true;         
//        }
//     return false;
// }


// string cycleDetection (vector<vector<int>>& edges, int n, int m)
// {
//     // Write your code here.   
    
//         vector<int> adj[n+1];

//     for(int i = 0;i<m;i++){
//         adj[edges[i][0]].push_back(edges[i][1]);
//         adj[edges[i][1]].push_back(edges[i][0]);
//     }
    
//     vector<bool> vis(n+1,0);    
//     for(int i=1;i<=n;i++){        
//         if(!vis[i] && isCycle(adj,vis,i,-1))
//             return "Yes";
//     }
//     return "No";
// }






bool isCycle(vector<int> adj[], int node, vector<bool>& vis){
    
    queue<pair<int,int>> q;    
    q.push({node,-1});
    vis[node] = true;
    
    while(!q.empty()){        
        int cur = q.front().first;
        int parent = q.front().second;
        q.pop();
        
        for(auto child : adj[cur]){            
            if(!vis[child]){
                q.push({child,cur});
                vis[child] = true;
            }
            else if(parent != child)return true;
        }      
    }
      return false;
}




string cycleDetection (vector<vector<int>>& edges, int n, int m)
{
    // Write your code here.   
    
    vector<int> adj[n+1];
    for(int i = 0;i<m;i++){
        adj[edges[i][0]].push_back(edges[i][1]);
        adj[edges[i][1]].push_back(edges[i][0]);
    }
    
    vector<bool> vis(n+1,false);   
    
    for(int i=1;i<=n;i++){        
        if( !vis[i] )
            if(isCycle(adj,i,vis))
              return "Yes";       
    }
    return "No";

}














