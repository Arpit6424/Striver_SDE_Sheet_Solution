#include<bits/stdc++.h>
struct node{
	int u;
	int v;
	int wt;
	node(int u, int v, int wt){
		this->u = u;
		this->v = v;
		this->wt = wt;
	}
};

bool comp(node a, node b){
	return a.wt < b.wt;
	
}

int findPar(int u, vector<int> &parent) {
    if(u == parent[u]) return u; 
    return parent[u] = findPar(parent[u], parent); 
}

void unionn(int u, int v, vector<int> &parent, vector<int> &rank) {
    u = findPar(u, parent);
    v = findPar(v, parent);
    if(rank[u] < rank[v]) {
    	parent[u] = v;
    }
    else if(rank[v] < rank[u]) {
    	parent[v] = u; 
    }
    else {
    	parent[v] = u;
    	rank[u]++; 
    }
}

int kruskalMST(int n, int m, vector<vector<int>> &graph) {
	
	vector<node> adj;
	
	for(int i=0;i<m;i++){
		int u = graph[i][0];
		int v = graph[i][1];
		int wt = graph[i][2];
		adj.push_back(node(u, v, wt));
	}
	
	sort(adj.begin(), adj.end(), comp);
	
	vector<int> parent(n+1);
	for(int i=1;i<=n;i++)
		parent[i] = i;
    
	vector<int> rank(n+1, 0);
	
// 	vector<pair<int,int>> mst;
	int cost=0;
	
	for(auto it : adj){
		
		if(findPar(it.v, parent) != findPar(it.u , parent)){
			cost += it.wt;
// 			mst.push_back({it.u,it.v});
			unionn(it.u, it.v, parent, rank);
			
		}
	}
	
	return cost;
	
}