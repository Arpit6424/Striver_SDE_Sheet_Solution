// class Solution {
    
//     int solve(int ind1, int ind2, string &text1,string &text2,vector<vector<int>>& dp){
         
//         if(ind1 == 0 || ind2 == 0)return 0;
//         if(dp[ind1][ind2] != -1)return dp[ind1][ind2];
        
//         if(text1[ind1-1] == text2[ind2-1]) return 1 + solve(ind1-1 ,ind2-1,text1,text2,dp);
        
//         return dp[ind1][ind2] = max(solve(ind1-1,ind2,text1,text2,dp),solve(ind1, ind2-1,text1,text2,dp));
//     }
// public:
//     int longestCommonSubsequence(string text1, string text2) {
        
//         int size1 = text1.size();
//         int size2 = text2.size();
        
//         vector<vector<int>> dp(size1+1,vector<int>(size2+1,-1));
        
//         return solve(size1,size2,text1,text2,dp);
 
        
//     }
// };




// class Solution {
// public:
//     int longestCommonSubsequence(string text1, string text2) {
        
//         int n = text1.size();
//         int m = text2.size();

//         vector<vector<int>> dp(n+1,vector<int>(m+1,0));

//         for(int ind1 = 0;ind1<=n;ind1++)dp[ind1][0] = 0;
//         for(int ind2 = 0;ind2<=m;ind2++)dp[0][ind2] = 0;
        
//         for(int ind1=1;ind1<=n;ind1++){
//             for(int ind2=1;ind2<=m;ind2++){
                
//                if(text1[ind1-1] == text2[ind2-1]) dp[ind1][ind2]  = 1 + dp[ind1-1][ind2-1];
        
//                 else dp[ind1][ind2] = max(dp[ind1-1][ind2],dp[ind1][ind2-1]);
//             }
//         }
        
//         return dp[n][m];
        
        
//     }
// };










class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        
        int n = text1.size();
        int m = text2.size();

        vector<int> prev(m+1,0),cur(m+1,0);    ;
        
        for(int ind1=1;ind1<=n;ind1++){
            for(int ind2=1;ind2<=m;ind2++){
                
               if(text1[ind1-1] == text2[ind2-1]) cur[ind2]  = 1 + prev[ind2-1];        
                else cur[ind2] = max(prev[ind2],cur[ind2-1]);
            }
            prev = cur;
        }
        
        return cur[m];       
        
    }
};