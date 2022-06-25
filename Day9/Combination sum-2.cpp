class Solution {
    
//     void solve(int ind,vector<int>& candidates, int target, vector<vector<int>> &ans, vector<int> &temp ){
        
//         if(ind == candidates.size()){
//             if(target==0)ans.push_back(temp);
//             return ;
//         }
        
//         if(candidates[ind]<=target){
           
//             temp.push_back(candidates[ind]);
//             solve(ind+1, candidates,target - candidates[ind],ans, temp);
//             temp.pop_back();            
//         }
        
//         while(ind+1<candidates.size() && candidates[ind]==candidates[ind+1])ind++;
//         solve(ind+1, candidates, target,ans, temp);
//     }
    
    void solve(int ind,vector<int>& candidates, int target, vector<vector<int>> &ans, vector<int> &temp,int n )     {
    if(target==0){
        ans.push_back(temp);
        return ;
    }
        
    for(int i=ind ;i<n;i++){
        
        if(i != ind && candidates[i]==candidates[i-1])continue;
        
        if(candidates[i]>target)break;
        temp.push_back(candidates[i]);
        solve(i+1, candidates,target - candidates[i],ans, temp,n);
        temp.pop_back();            
    }
}
    
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        int n = candidates.size();
        sort(candidates.begin(),candidates.end());
        vector<vector<int>> ans;
        vector<int> temp;
        solve(0,candidates,target,ans, temp,n);
        return ans;
        
    }
};