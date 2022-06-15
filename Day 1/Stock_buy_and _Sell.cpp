class Solution {
public:
    int maxProfit(vector<int>& prices) {
        
        int mini = INT_MAX;
        int maxProfit = 0;
        
        for(int i=0;i<prices.size();i++){
            
            int cost = prices[i] - mini;
            maxProfit = max(maxProfit, cost);
            
            mini = min(mini, prices[i]);
        }
        return maxProfit;
        
    }
};