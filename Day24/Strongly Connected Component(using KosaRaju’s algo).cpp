
#include<bits/stdc++.h>
void revtopoSort(int node,vector<int> graph[], vector<bool>& vis,vector<int>& ds ){
    
    vis[node] = true;    
    for(auto it: graph[node]){        
        if(!vis[it])
            revtopoSort(it,graph,vis,ds);
    }    
   ds.push_back(node);
}


void dfstopoSort(int node,vector<int> graph[], vector<bool>& vis, stack<int>& st )
{
    
    vis[node] = true;    
    for(auto it: graph[node]){        
        if(!vis[it])
            dfstopoSort(it,graph,vis,st);
    }    
    st.push(node);
}

vector<vector<int>> stronglyConnectedComponents(int n, vector<vector<int>> &edges)
{
    vector<vector<int>> ans;
     
    vector<int> graph[n];    
    for(int i=0;i<edges.size();i++){
        graph[edges[i][0]].push_back(edges[i][1]);
    }
    
    vector<bool> vis(n,false);
    stack<int> st;    
    for(int i=0;i<n;i++){
        if(!vis[i])
          dfstopoSort(i,graph,vis,st);
    }
    

    vector<int> tra[n];
    for(int i=0;i<n;i++){
        vis[i]=0;
        for(auto it: graph[i]){
            tra[it].push_back(i);
        }
    }
    while(!st.empty()){
        
        int node = st.top();
        st.pop();
        if(!vis[node]){
            vector<int> temp;
            revtopoSort(node,tra,vis,temp);
            ans.push_back(temp);
        }  
       
    }
    return ans;
}