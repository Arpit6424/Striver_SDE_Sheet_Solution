//  class Solution {
    
//     int solve(int i,int j,vector<vector<int>>& grid,int dp[201][201]){
        
//         if(i==0 && j==0)return  grid[i][j];        
//         if(i<0|| j<0)return 1e8;
        
//         if(dp[i][j] != -1)return dp[i][j];
        
     

//         int left = grid[i][j] + solve(i,j-1,grid,dp);
//         int up =   grid[i][j] + solve(i-1,j,grid,dp);
       
               
//         return dp[i][j] =  min(left,up);
        
//     }
    
// public:
//     int minPathSum(vector<vector<int>>& grid) {
        
//         int m = grid.size();
//         int n = grid[0].size();
        
//         int dp[201][201];
//         memset(dp,-1,sizeof(dp));

//         return solve(m-1,n-1,grid,dp);
        
//     }
// };






//  class Solution {    
// public:
//     int minPathSum(vector<vector<int>>& grid) {
        
//         int m = grid.size();
//         int n = grid[0].size();
        
//         int dp[201][201];
//         memset(dp,-1,sizeof(dp));
        
//         dp[0][0] = grid[0][0];

//         for(int i=0;i<m;i++){
//             for(int j=0;j<n;j++){                
//                 if(i==0 && j==0)dp[i][j] = grid[i][j];
//                 else{                    
//                     int left = 1e8;
//                     int up  =  1e8;
                     
//                     if(j-1 >=0) left = dp[i][j-1];
//                     if(i-1 >= 0)up =   dp[i-1][j];
//                     dp[i][j] = min(left,up) + grid[i][j];
//                 }          
//             }
//         }
//         return dp[m-1][n-1];        
//     }
// };













//Space optimize

 class Solution {    
public:
    int minPathSum(vector<vector<int>>& grid) {
        
        int m = grid.size();
        int n = grid[0].size();
         
        vector<int> cur(201,0),prev(201,0);
        
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){                
                if(i==0 && j==0)cur[j] = grid[i][j];
                else{                    
                    int left = 1e8;
                    int up  =  1e8;
                     
                    if(j-1 >=0) left = cur[j-1];
                    if(i-1 >= 0)up =   prev[j];
                    cur[j] = min(left,up) + grid[i][j];
                }          
            }
            prev = cur;
        }
        return cur[n-1];        
    }
};