#include<bits/stdc++.h>
vector<pair<pair<int, int>, int>> calculatePrimsMST
(int n, int m, vector<pair<pair<int, int>, int>> &g)
{
    vector<pair<int, int> > adj[n+1];
	
	for(int i=0;i<m;i++){
		int a = g[i].first.first;
		int b = g[i].first.second;
	    int wt = g[i].second;
		
		adj[a].push_back({b,wt});
		adj[b].push_back({a,wt});
	}
	
	int parent[n+1];
	int key[n+1];
	bool mstSet[n+1];
	
	for(int i=0;i<=n;i++){
		key[i]=INT_MAX, mstSet[i]=false;
	}
	priority_queue< pair<int,int>, vector <pair<int,int>> , greater<pair<int,int>> > pq;
	
	key[1] = 0;
	parent[1] = -1;
	pq.push({0,1});
	
	while(!pq.empty()){
		int u = pq.top().second;
		pq.pop();
		
		mstSet[u]= true;
		
		for(auto it:adj[u]){
			int v = it.first;
			int wt = it.second;
			
			if(mstSet[v]==false && wt < key[v]){
				
				parent[v] = u;
				key[v] = wt;
				pq.push({key[v],v});
			}
		}
	}
	
	vector<pair<pair<int, int>, int>> ans;
	
	for(int i=2;i<=n;i++){
		
		for(auto it : adj[parent[i]]){
			if(it.first==i){
				int u = parent[i];
				int v= i;
				int wt =it.second;
				
				ans.push_back( { {u,v}, wt});
			}
				
		}
		return ans;
	}
	
	
	
}
