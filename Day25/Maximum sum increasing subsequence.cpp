//class Solution{
	
// 	int solve(int cur,int prev ,int arr[],int n,vector<vector<int>> &dp){
	    
// 	    if(cur==n)return 0;
// 	    if(dp[cur][prev+1] != -1)return dp[cur][prev+1];
	    
// 	    int notpick = 0 + solve(cur+1,prev,arr,n,dp);
	    
// 	    int pick = INT_MIN;
// 	    if(prev == -1 || arr[cur] > arr[prev])
// 	      pick = arr[cur] + solve(cur+1,cur,arr,n,dp);
	      
// 	    return dp[cur][prev+1] =  max(pick,notpick);
// 	}	

// 	public:
// 	int maxSumIS(int arr[], int n)  
// 	{  
// 	    // Your code goes here
// 	    vector<vector<int>> dp(n,vector<int>(n+1,-1));
// 	    return solve(0,-1,arr,n,dp);
// 	}  
// };











class Solution{
    public:
	int maxSumIS(int arr[], int n)  
	{  
	    // Your code goes here
	    vector<vector<int>> dp(n+1,vector<int>(n+1,0));
	   
	   for(int cur=n-1;cur>=0;cur--){
	       
	       for(int prev=n-1;prev>=-1;prev--){
	           
	            int notpick = 0 + dp[cur+1][prev+1];
	    
        	    int pick = INT_MIN;
        	    if(prev == -1 || arr[cur] > arr[prev])
        	      pick = arr[cur] + dp[cur+1][cur+1];
        	     
        	     dp[cur][prev+1] =  max(pick,notpick);
	           
	           
	       }
	   }
	   return dp[0][0];
	}  
};
