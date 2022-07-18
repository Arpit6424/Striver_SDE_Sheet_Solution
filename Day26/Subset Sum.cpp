// class Solution {
    
//     bool solve(int ind, vector<int>& nums, int tar,vector<vector<int>>& dp){
        
//         if(ind==0){
//             if(tar==0 || tar-nums[0]==0)return true;
//             return false;
//         }
        
//         if(dp[ind][tar] != -1)return dp[ind][tar];
        
//         bool notpick = solve(ind-1,nums,tar,dp);
        
//         bool pick = false;
//         if(nums[ind]<= tar)
//             pick = solve(ind-1,nums,tar-nums[ind],dp);
        
//         return dp[ind][tar] =  pick || notpick;
//     }
    
// public:
//     bool canPartition(vector<int>& nums) {
        
//         int sum =0;
//         for(auto it: nums)sum += it;        
//         if(sum%2 != 0)return false;
//         int tar = sum/2;
        
//         vector<vector<int>> dp(nums.size(),vector<int>(tar+1,-1));
        
//         return solve(nums.size()-1,nums,tar,dp);
        
//     }
// };









class Solution {    
public:
    bool canPartition(vector<int>& nums) {
        
        int sum =0;
        for(auto it: nums)sum += it;        
        if(sum%2 != 0)return false;
        int target = sum/2;
        
        int n = nums.size();
        vector<vector<int>> dp(n,vector<int>(target+1,0));
        
        for(int ind=0;ind<n;ind++){
            dp[ind][0] = true;            
        }
          if(nums[0]<=target)
                dp[0][nums[0]] = true;
        
        
        for(int ind=1;ind<n;ind++){
            for(int tar =1; tar<=target;tar++){
                
                bool notpick = dp[ind-1][tar];

                bool pick = false;
                if(nums[ind]<= tar)
                    pick =dp[ind-1][tar-nums[ind]];

                 dp[ind][tar] =  pick || notpick;
                
            }
        }
       
        return dp[n-1][target];
        
    }
};