class Solution
{
    int solve(int n, int k,int dp[201][201]){
        if(k==1 || k==0 || n==1 )return k;
        if(dp[n][k] != -1)return dp[n][k];
        
        int ans = INT_MAX;
        for(int i=1;i<=k;i++){
            int temp = 1 + max( solve(n-1,i-1,dp),solve(n,k-i,dp));
            ans = min(ans,temp);
        }
        return dp[n][k]= ans;
    }
    public:
    //Function to find minimum number of attempts needed in 
    //order to find the critical floor.
    int eggDrop(int n, int k) 
    {
        // your code here
        int dp[201][201];
        memset(dp,-1,sizeof dp);
        return solve(n,k,dp);
    }
};