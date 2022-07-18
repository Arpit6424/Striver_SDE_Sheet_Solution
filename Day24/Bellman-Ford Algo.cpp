
#include<bits/stdc++.h>
struct node{
	int u,v,wt;
	node(int u, int v, int wt){
		this->u = u;
		this->v = v;
		this->wt = wt;
	}
};

int bellmonFord(int n, int m, int src, int dest, vector<vector<int>> &edges) {
    vector<node> adj;
	for(int i=0;i<m;i++){
        int u = edges[i][0];
	    int v = edges[i][1];
	    int wt = edges[i][2];
		
	  adj.push_back(node(u,v,wt));
	}
		int inf = INT_MAX;
	vector< int> distTo(n+1,inf);
	
	distTo[src] = 0;
	
	for(int i=0;i<n-1;i++){
		for(auto it : adj){
			if((long long)distTo[it.u] + it.wt < distTo[it.v]){
				distTo[it.v] = distTo[it.u] + it.wt;
			}
		}
	}

	
	if(distTo[dest]<1e9)return distTo[dest];
	else return 1e9;
	
	

	
}
