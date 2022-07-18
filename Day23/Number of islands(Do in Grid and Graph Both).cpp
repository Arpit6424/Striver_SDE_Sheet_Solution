// class Solution {
    
//     void dfs(int i, int j,vector<vector<char>>& grid,vector<vector<bool>>& vis ){
        
//         if(i<0 || j<0 || i==grid.size() || j==grid[0].size() || vis[i][j] || grid[i][j]=='0')return ;        
        
//         vis[i][j]=true;
//         dfs(i+1,j,grid,vis);
//         dfs(i-1,j,grid,vis);
//         dfs(i,j+1,grid,vis);
//         dfs(i,j-1,grid,vis);
//     }
    
// public:
//     int numIslands(vector<vector<char>>& grid) {
        
//         int m = grid.size();
//         int n = grid[0].size();
        
//         int islands =0;
//         vector<vector<bool>> vis(m,vector<bool>(n,false));
        
//         for(int i=0;i<m;i++){            
//             for(int j=0;j<n;j++){                
//                 if(!vis[i][j] && grid[i][j] == '1'){
//                     dfs(i,j,grid,vis);
//                     islands++;                    
//                 }                    
//             }
//         }
        
//         return islands;
        
//     }
// };







class Solution {
    
    void dfs(int i, int j,vector<vector<char>>& grid,int n,int m ){
        
        if(i<0 || j<0 || i==m || j==n ||  grid[i][j]!='1')return ;        
        
        grid[i][j]='2';
        dfs(i+1,j,grid,n,m);
        dfs(i-1,j,grid,n,m);
        dfs(i,j+1,grid,n,m);
        dfs(i,j-1,grid,n,m);
    }
    
public:
    int numIslands(vector<vector<char>>& grid) {
        
        int m = grid.size();
        int n = grid[0].size();
        
        int islands =0;
        
        for(int i=0;i<m;i++){            
            for(int j=0;j<n;j++){                
                if(grid[i][j] == '1'){
                    dfs(i,j,grid,n,m);
                    islands++;                    
                }                    
            }
        }
        
        return islands;
        
    }
};