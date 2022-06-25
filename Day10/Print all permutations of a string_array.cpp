// class Solution {
    
    
//     void solve(vector<int>& nums, vector<int>& ds, vector<int> &vis, vector<vector<int>> &ans  ){
        
//         if(ds.size()==nums.size()){
//             ans.push_back(ds) ;
//             return ;
//         }
        
        
//         for(int ind=0;ind<nums.size();ind++){
           
//            if(!vis[ind]) {
               
//                ds.push_back(nums[ind]);
//                vis[ind] = 1;
//                solve(nums,ds,vis, ans);
               
//                ds.pop_back();
//                vis[ind] = 0;
//            }
           
         
//         }
//     }
    
    
// public:
//     vector<vector<int>> permute(vector<int>& nums) {
//         vector<vector<int>> ans;
        
//         int numsLen = nums.size();
//         vector<int> ds;
//         vector<int> vis(numsLen,0);
        
//         solve(nums, ds, vis,ans);
        
         
//         return ans;
        
//     }
// };



















class Solution {
    
    void solve(int ind, vector<int> &nums, vector<vector<int>> &ans,int n){
        
        if(ind==n){
            ans.push_back(nums);
            return ;
       
        }
        
        
        for(int i = ind;i<n;i++){
            
            //swap the value
            int temp = nums[i];
            nums[i] = nums[ind];
            nums[ind] = temp;
            
            solve(ind+1,nums,ans,n);
            
             //swap the value backtracking
             temp = nums[i];
            nums[i] = nums[ind];
            nums[ind] = temp;
        }
        
        
        
    }
 
    
public:
    vector<vector<int>> permute(vector<int>& nums) {
        
        vector<vector<int>> ans;
        int n = nums.size();
        
        solve(0,nums,ans,n);
        return ans;
        
      
        
    }
};