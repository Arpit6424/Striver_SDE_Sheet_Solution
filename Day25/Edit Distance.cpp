// class Solution {
    
//     int solve(int ind1, int ind2,string &word1, string &word2,vector<vector<int>>& dp ){
        
//         if(ind1==0)return ind2;
//         if(ind2==0)return ind1;
        
//         if(dp[ind1][ind2] != -1)return dp[ind1][ind2];
//         if(word1[ind1-1] == word2[ind2-1])return 0 + solve(ind1-1,ind2-1, word1,word2,dp);
        
//         int insert =  1 + solve(ind1-1,ind2,word1,word2,dp);
//         int remove =  1 + solve(ind1 , ind2-1,word1,word2,dp);
//         int replace = 1 + solve(ind1-1,ind2-1,word1,word2,dp);
        
//         return dp[ind1][ind2] = min({insert,remove,replace});
        
    
        
//     }
// public:
//     int minDistance(string word1, string word2) {
        
//         int n = word1.size();
//         int m = word2.size();
        
//         vector<vector<int>> dp(n+1,vector<int>(m+1,-1));
        
//         return solve(n,m,word1,word2,dp);
        
//     }
// };













// class Solution {
// public:
//     int minDistance(string word1, string word2) {
        
//         int n = word1.size();
//         int m = word2.size();
        
//         vector<vector<int>> dp(n+1,vector<int>(m+1,0));
        
//         for(int ind2=0;ind2<=m;ind2++) dp[0][ind2] = ind2;
//         for(int ind1=0;ind1<=n;ind1++) dp[ind1][0] = ind1;
        
        
//         for(int ind1=1;ind1<=n;ind1++){
//             for(int ind2=1;ind2<=m;ind2++){       
//                 if(word1[ind1-1] == word2[ind2-1])dp[ind1][ind2] = 0 + dp[ind1-1][ind2-1];               
                
//                 else{
//                     int insert =  1 + dp[ind1-1][ind2];
//                     int remove =  1 + dp[ind1][ind2-1];
//                     int replace = 1 + dp[ind1-1][ind2-1];

//                     dp[ind1][ind2] = min({insert,remove,replace});                    
//                 }                
//             }
//         }
//         return dp[n][m];
//     }
// };














class Solution {
public:
    int minDistance(string word1, string word2) {
        
        int n = word1.size();
        int m = word2.size();
        
        vector<int> cur(m+1,0),prev(m+1,0);
        
   
         for(int ind2=0;ind2<=m;ind2++)
             prev[ind2] = ind2;
        
        
        for(int ind1=1;ind1<=n;ind1++){
            cur[0] = ind1;
            for(int ind2=1;ind2<=m;ind2++){       
                if(word1[ind1-1] == word2[ind2-1])cur[ind2] = 0 + prev[ind2-1];               
                
                else{
                    int insert =  1 + prev[ind2];
                    int remove =  1 + cur[ind2-1];
                    int replace = 1 + prev[ind2-1];

                    cur[ind2] = min({insert,remove,replace});                    
                }                
            }
            prev = cur;
        }
        return prev[m];
    }
};















