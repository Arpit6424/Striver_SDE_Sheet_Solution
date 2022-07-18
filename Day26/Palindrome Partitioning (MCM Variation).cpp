bool isPalindrome(int st,int end,string &str){

    while(st<end){
        
        if(str[st] != str[end])return false;
        st++;end--;
    }
    return true;
}
class Solution{
    
    int solve(int ind , string& str,vector<int>& dp){
        
        if(ind==str.length())return 0;
        if(dp[ind] != -1)return dp[ind];
        
        int mini = INT_MAX;
        for(int i = ind ;i<str.length();i++){
            
            if(isPalindrome(ind,i,str)){
                
                int cost = 1 + solve(i+1,str,dp);
                mini = min(mini,cost);
            }
        }
        return dp[ind] = mini;
    }
public:
    int palindromicPartition(string str)
    {
        // code here
        vector<int> dp(str.length(),-1);
        return solve(0,str,dp)-1;
    }
};