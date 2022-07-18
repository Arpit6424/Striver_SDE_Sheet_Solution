#include<bits/stdc++.h>
vector<int> topologicalSort(vector<vector<int>> &edges, int v, int e)  {
   
	vector<int> adj[v];
	
	for(int i=0;i<edges.size();i++){
		adj[ edges[i][0]].push_back(edges[i][1]);
	}
	
	vector<int> inDegree(v, 0);
	
	for(int i=0;i<v;i++){
		for(auto it : adj[i])
			inDegree[it]++;
	}
	
	vector<int> topo;
	
	queue<int> q;
	
	for(int i=0;i<v;i++)
		if(inDegree[i]==0)q.push(i);
	
	while(!q.empty()){
		
		int node = q.front();
		q.pop();
		topo.push_back(node);
		for(auto it : adj[node]){
			inDegree[it]--;
			if(inDegree[it]==0)
				q.push(it);
		}
	}
	
	return topo;
}