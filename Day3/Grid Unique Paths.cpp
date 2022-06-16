// class Solution {
    
    
//     int solve(int i, int j,vector<vector<int>>& dp ){
        
//          if(i<0 || j<0)return 0;
        
//         if(i==0 && j==0)
//             return 1;
        
//         if(dp[i][j]  != -1)return dp[i][j];
       
        
        
//         int left = solve(i , j-1,dp);
//         int top = solve(i-1,j,dp);
        
//         return dp[i][j] =  (left + top);
//     }
    
    
// public:
//     int uniquePaths(int m, int n) {
        
//         vector<vector<int>> dp(m,vector<int>(n,-1));
//         return solve(m-1,n-1,dp);
        
//     }
// };








// class Solution {

    
// public:
//     int uniquePaths(int m, int n) {
        
//         vector<vector<int>> dp(m,vector<int>(n,0));
        
        
//         for(int i=0;i<m;i++){
//             for(int j=0;j<n;j++){
                
//                 if(i==0 && j==0){
//                     dp[i][j] = 1;
//                     continue;
//                 }
                
//                 int right = 0,  bottom = 0;
                
//                 if(j>0) right = dp[i][j-1];
//                 if(i>0) bottom = dp[i-1][j];

//                  dp[i][j] =  (right + bottom);
                
                
//             }
//         }
//         return dp[m-1][n-1];
        
//     }
// };








// class Solution {

    
// public:
//     int uniquePaths(int m, int n) {
        
//         vector<int> prev(n,0) ,cur(n,0);
        
        
//         for(int i=0;i<m;i++){
//             for(int j=0;j<n;j++){
                
//                 if(i==0 && j==0){
//                     cur[j] = 1;
//                     continue;
//                 }
                
//                 int right = 0,  bottom = 0;
                
//                 if(j>0) right = cur[j-1];
//                 if(i>0) bottom = prev[j];

//                  cur[j] =  (right + bottom);
                
                
//             }
//             prev = cur;
//         }
//         return cur[n-1];
        
//     }
// };







class Solution {

    
public:
    int uniquePaths(int m, int n) {
        
       
        int N = n+m-2;
        int r = m-1;
        
        double res =1;
        
        for(int i=1;i<=r;i++){
            res = res * (N-r+i)/i;
            
        }
        return (int)res;
    }
};

















