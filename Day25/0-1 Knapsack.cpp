// class Solution {    
//     pair<int,int> sumZeroOne(string &str){         
//         int Zero = 0,One = 0;
//         for(auto it : str){            
//             if(it == '0')Zero++;
//             else One++;
//         }
//         return {Zero,One};
//     }
    
//    int solve(vector<string>& strs, int m, int n ,int ind, int dp[101][101][601]){       
//        if(ind  < 0)return 0;
//        if(dp[m][n][ind] != -1)return dp[m][n][ind];
       
//        auto p = sumZeroOne(strs[ind]);    
//        int pick = INT_MIN;       
//        if(p.first <= m && p.second<=n)           
//             pick = 1 + solve(strs,m-p.first , n-p.second,ind-1,dp);      
       
//        int notpick = 0 + solve(strs,m,n,ind-1,dp);
       
//        return dp[m][n][ind] =  max(pick , notpick);     
       
//    }
// public:
//     int findMaxForm(vector<string>& strs, int m, int n) {    
        
//         int dp[101][101][601];
//         memset(dp,-1,sizeof(dp));
//         return solve(strs,m,n,strs.size()-1 , dp);        
//     }
// };


//swifting the index
// class Solution {    
//     pair<int,int> sumZeroOne(string &str){         
//         int Zero = 0,One = 0;
//         for(auto it : str){            
//             if(it == '0')Zero++;
//             else One++;
//         }
//         return {Zero,One};
//     }
    
//    int solve(vector<string>& strs, int m, int n ,int ind, int dp[101][101][601]){       
//        if(ind  == 0)return 0;
//        if(dp[m][n][ind] != -1)return dp[m][n][ind];
       
//        auto p = sumZeroOne(strs[ind-1]);    
//        int pick = INT_MIN;       
//        if(p.first <= m && p.second<=n)           
//             pick = 1 + solve(strs,m-p.first , n-p.second,ind-1,dp);      
       
//        int notpick = 0 + solve(strs,m,n,ind-1,dp);
       
//        return dp[m][n][ind] =  max(pick , notpick);     
       
//    }
// public:
//     int findMaxForm(vector<string>& strs, int m, int n) {    
        
//         int dp[101][101][601];
//         memset(dp,-1,sizeof(dp));
//         return solve(strs,m,n,strs.size() , dp);        
//     }
// };


class Solution {    
    pair<int,int> sumZeroOne(string &str){         
        int Zero = 0,One = 0;
        for(auto it : str){            
            if(it == '0')Zero++;
            else One++;
        }
        return {Zero,One};
    }

public:    
// int findMaxForm(vector<string>& strs, int m, int n) {  
//         int len = strs.size();
//         vector<vector<vector<int>>> dp(len+1, vector<vector<int>>(m+1, vector<int>(n+1,0)));
//         for(int i=1; i<len+1; i++){
//             auto p = sumZeroOne(strs[i-1]);
//             for(int j=0; j<m+1; j++){
//                 for(int k=0; k<n+1; k++){
//                     if(p.first<=m && p.second<=n && p.first <= j && p.second <= k){
//                         dp[i][j][k] = max(dp[i-1][j][k], 1 + dp[i-1][j-p.first][k-p.second]);
//                     }
//                     else{
//                         dp[i][j][k] = dp[i-1][j][k];
//                     }
//                 }
//             }
//         }
//         return dp[len][m][n];
// }
    
    
    
    
int findMaxForm(vector<string>& strs, int m, int n) {  
    int len = strs.size();
    int dp[101][101][601];
    memset(dp,0,sizeof(dp));

    for(int i=0; i<=m; i++){           
        for(int j=0; j<n+1; j++){
            for(int k=1; k<=len; k++){
                 auto p = sumZeroOne(strs[k-1]);

                 int pick = INT_MIN;
                 if(p.first<=m && p.second<=n && p.first <= i && p.second <= j)
                    pick =  1 + dp[i-p.first][j-p.second][k-1];                   

                 int notpick = dp[i][j][k-1];                    
                 dp[i][j][k] = max(pick,notpick);

            }
        }
    }
    return dp[m][n][len];
}
};