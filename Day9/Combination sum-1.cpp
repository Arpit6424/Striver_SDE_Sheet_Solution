class Solution {
    
    void solve(int ind,vector<int>& candidates, int target,vector<int> &temp, vector<vector<int>> &ans ){
        if(target==0){
            ans.push_back(temp);
            return ;
        }
        if(ind==candidates.size()) return ;
        
        solve(ind+1, candidates, target,temp,ans);
        
        if(candidates[ind]<=target){
        temp.push_back(candidates[ind]);
        solve(ind, candidates, target-candidates[ind],temp, ans);
        temp.pop_back();
        }
        
    }
    
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        
        vector<vector<int>> ans;
        vector<int> temp;
        
        solve(0, candidates, target, temp, ans);
        return ans;
        
    }
};