
#include<bits/stdc++.h>
vector<int> dijkstra(vector<vector<int>> &vec, int vertices, int edges, int source) {
    
	vector<pair<int,int>>  adj[vertices];
	
	for(int i=0;i<edges;i++){
		
		adj[ vec[i][0] ].push_back( make_pair(vec[i][1], vec[i][2]));
		adj[ vec[i][1] ].push_back( make_pair(vec[i][0], vec[i][2]));
	}
	
	
	priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
	
	int src=0;
	pq.push({0,src});
	
	vector<int> distTo(vertices, INT_MAX);
	distTo[src] = 0;
	
	while(!pq.empty()){
		int dist = pq.top().first;
		int prev = pq.top().second;
		pq.pop();
		
		for(auto it: adj[prev]){
			int next = it.first;
			int nextDist = it.second;
			
			if(distTo[next] >dist + nextDist){
				distTo[next] = dist + nextDist;
				pq.push({distTo[next],next});
			}
		}
	}
	return distTo;
}
