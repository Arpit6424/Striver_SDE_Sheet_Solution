// class Solution {
    
//     int solve(int ind,int prev_Ind , vector<int>& nums,vector<vector<int>>& dp){
        
//         if(ind==nums.size())return 0;
        
//         if(dp[ind][prev_Ind+1] != -1)return dp[ind][prev_Ind+1];
        
//         int notpick = 0 + solve(ind+1,prev_Ind,nums,dp);
        
        
//         int pick = INT_MIN;
//         if(prev_Ind == -1 || nums[ind]>nums[prev_Ind])
//             pick =    1 + solve(ind+1,ind,nums,dp);       
                      
        
//         return dp[ind][prev_Ind+1] = max(pick,notpick);
//     }
    
// public:
//     int lengthOfLIS(vector<int>& nums) {
        
//         int n = nums.size();
//         vector<vector<int>> dp(n,vector<int>(n+1,-1));
//         return solve(0,-1,nums,dp);
        
//     }
// };


class Solution {    
public:
    int lengthOfLIS(vector<int>& nums) {
        
        int n = nums.size();
        vector<vector<int>> dp(n+1,vector<int>(n+1,0));
        
        
        for(int ind=n-1;ind>=0;ind--){
            
            for(int prev = ind-1;prev>=-1;prev--){
                
                int notpick = dp[ind+1][prev+1];        
        
                int pick = INT_MIN;
                if(prev == -1 || nums[ind]>nums[prev])
                    pick =    1 + dp[ind+1][ind+1];       
                      
        
                 dp[ind][prev+1] = max(pick,notpick);
                
            }
        }
        
        return dp[0][0];
    }
};