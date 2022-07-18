class Solution
{
    public:
    int wordBreak(string A, vector<string> &B) {
        unordered_set<string> st;
        for(const auto &str: B) st.insert(str);
        
        vector<int> dp(A.size() + 1, 0);
        for(int i = 1; i <= A.size(); i++) {
            if(st.find(A.substr(0, i)) != st.end()) dp[i] = 1;
            for(int j = 1; j <= i; j++) {
                string part1 = A.substr(0, j);
                string part2 = A.substr(j, i - j);
                if(st.find(part2) != st.end()) dp[i] += dp[j];
            }
        }
        
        return dp[A.size()];
    }
};