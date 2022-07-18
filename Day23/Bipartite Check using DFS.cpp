
#include<bits/stdc++.h>

bool bipartiteGraph(int src, vector<int> &color ,vector<int>adj[] ){
	
	color[src] = 1;
	
	queue<int> q;
	q.push(src);
	
	while(!q.empty()){
		int node = q.front();
		q.pop();
		
		for(auto it : adj[node]){
				if(color[it]==-1){
					
					color[it] = 1-color[node];
					q.push(it);
				}
				else if(color[it] == color[node])return false;
				
			
		}
	}
	return true;
	
}


bool isGraphBirpatite(vector<vector<int>> &edges) {
	
	int n = edges[0].size();
	
	vector<int> adj[n];

	   for(int i=0;i<n;i++)
         for(int j=0;j<n;j++)
            if(edges[i][j]==1){
                adj[i].push_back(j);
                adj[j].push_back(i);
            }
        
    
	
	vector<int> color(n,-1);
	
	for(int i=0;i<n;i++){
		
		if(color[i]==-1){
			if( bipartiteGraph(i, color, adj) == false)return false;
		}
	}
	return true;
}