// class Solution {
    
//     int solve(vector<int>& coins, int amount,vector<int>& dp){

            
//      if(amount==0)
//               return 0;
//         if(dp[amount] != -1)return dp[amount];
          
//         int  ans = 1e8;
//         for(int i=coins.size()-1;i>=0;i--){
            
//             int count = 1e8;
//             if(coins[i] <=amount)
//                count = 1 +  solve(coins,amount-coins[i],dp);
            
//             ans = min(ans,count);
            
//         }        
//         return dp[amount] = ans;      
           
//     }
// public:
//     int coinChange(vector<int>& coins, int amount) {
        
        
//         vector<int> dp(amount+1,-1);
        
//         int ans = solve(coins,amount,dp);
        
//         if(ans>=1e8)return -1;
//         return ans;
        
//     }
// };









// class Solution {
    
//     int solve(int ind ,vector<int>& coins, int amount,vector<vector<int>>& dp){        

//         if(ind==0){         
//              if(amount % coins[0] == 0)return amount/coins[0];
//              return 1e8;
//         }
        
//         if(dp[ind][amount] != -1)return dp[ind][amount];
//         int notTake = 0 + solve(ind-1,coins,amount,dp);
        
//         int take = 1e8;
//         if(coins[ind] <=amount)
//             take = 1 + solve(ind,coins,amount-coins[ind],dp);        
//         return dp[ind][amount] = min(take,notTake);           
//     }
// public:
//     int coinChange(vector<int>& coins, int amount) {           
              
//         vector<vector<int>> dp(coins.size(),vector<int>(amount+1,-1));
//         int ans = solve(coins.size()-1,coins,amount,dp);
        
//         if(ans>=1e8)return -1;
//         return ans;
        
//     }
// };



// class Solution {
// public:
//     int coinChange(vector<int>& coins, int amount) {           
              
//         vector<vector<int>> dp(coins.size(),vector<int>(amount+1,0));
        
//         for(int amt=0;amt<=amount;amt++){
//             if(amt % coins[0]==0)dp[0][amt] = amt/coins[0];
//             else dp[0][amt] = 1e8;
            
//         }         
        
        
//         for(int i=1;i<coins.size();i++){
            
//             for(int amt=0;amt<=amount;amt++){
                
//                 // if(i==0){
//                 //      if(amt % coins[0]==0)dp[0][amt] = amt/coins[0]; //we can write base case here also just change i=0->i->n in first loop
//                 //      else dp[0][amt] = 1e8;
//                 //     continue;                   
//                 // }
                
//                 int notTake = 0 + dp[i-1][amt];

//                 int take = 1e8;
//                 if(coins[i] <=amt)
//                     take = 1 + dp[i][amt-coins[i]];        
//                 dp[i][amt] = min(take,notTake);
                
//             }
//         }

//         if(dp[coins.size()-1][amount] >= 1e8)return -1;
//         return dp[coins.size()-1][amount];

        
//     }
// };




class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {           
              
        vector<int> dp(amount+1,0);
        
        for(int amt=0;amt<=amount;amt++){
            if(amt % coins[0]==0)dp[amt] = amt/coins[0];
            else dp[amt] = 1e8;
            
        }         
        
        
        for(int i=1;i<coins.size();i++){            
            for(int amt=0;amt<=amount;amt++){
                
                int notTake = 0 + dp[amt];

                int take = 1e8;
                if(coins[i] <=amt)
                    take = 1 +dp[amt-coins[i]];        
                dp[amt] = min(take,notTake);
                
            }
        }

        if(dp[amount] >= 1e8)return -1;
        return dp[amount];

        
    }
};





