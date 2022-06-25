bool isSafe(int node,int color,bool graph[101][101], int n,int all_nodes[]){
    
    for(int k=0;k<n;k++){
        if(k != node && graph[k][node] == 1 && all_nodes[k] == color ){
            return false;
        }
    }
    return true;
}

bool solve(int node,bool graph[101][101], int m, int n,int all_nodes[]){
    
    if(node==n){
        return true;
    }
    
    for(int color=1;color<=m;color++){
        if(isSafe(node,color,graph,n,all_nodes)){
            all_nodes[node] = color;
            if(solve(node+1,graph,m,n,all_nodes))return true;
            all_nodes[node] = 0;
        }
    }
    return false;
}


bool graphColoring(bool graph[101][101], int m, int n) {
    
    
    int all_nodes[n] ={0};
    return solve(0,graph ,m,n,all_nodes);
    // your code here
}