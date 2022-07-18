#include<bits/stdc++.h>
//Kahn's Algrithm finding topo sort(cycle in directed graph) using bfs traversal;
int detectCycleInDirectedGraph(int n, vector < pair < int, int >> & edges) {
  
    vector<int> adj[n+1];
    
    for(int i=0;i<edges.size();i++){
        adj[edges[i].first].push_back(edges[i].second);
    }
    vector<int> indegree(n+1, 0);
    for(int i = 1;i<=n;i++){
        for(auto it: adj[i])
            indegree[it]++;
    }
    
    queue<int> q;
    
    for(int i=1;i<=n;i++)
        if(indegree[i]==0)
            q.push(i);
    
    int cnt=0;
    
    while(!q.empty()){
        int node = q.front();
        q.pop();
        cnt++;

        for(auto it: adj[node]){
            indegree[it]--;
            if(indegree[it]==0)
                q.push(it);
        }
    }
    
    if(cnt != n)return 1;
    return 0;
}








//Cycle detect by DFS Traversal

// bool isCycle(int node,vector<int> graph[],vector<bool>&vis, vector<bool>& dfsVis){    
//     vis[node] = true;
//     dfsVis[node] = true;    
//     for(auto child : graph[node]){        
//         if(!vis[child]){
//             if(isCycle(child,graph,vis,dfsVis)) return true;
//         }
//         else if(dfsVis[child])return true;
//     }
//     dfsVis[node] = false;
//     return false;
// }

// int detectCycleInDirectedGraph(int n, vector < pair < int, int >> & edges) {.
//     vector<int> graph[n+1];
//     for(int i=0;i<edges.size();i++){
//         graph[edges[i].first].push_back(edges[i].second);
//     }    
//     vector<bool> vis(n+1,false);    
//     vector<bool> dfsVis(n+1,false);    
//     for(int i=1;i<=n;i++){        
//         if(!vis[i])
//            if(isCycle(i,graph,vis,dfsVis)  )return 1;
//     }
//     return 0; 
// }








