


class Solution {

public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        
        sort(nums.begin(),nums.end());
        vector<vector<int>> ans;
        int n = nums.size();
        
        for(int i=0;i<n-2;i++){
            
            if(i>0 && nums[i] == nums[i-1] )continue;
            
            int low = i+1;
            int high = n-1;
            int tar = -(nums[i]);
            
            while(low<high){
                
                if(nums[low]+nums[high]==tar){
                    
                    ans.push_back({nums[i],nums[low],nums[high]});
                    low++,high--;
                    
                    while(low<high && nums[low] == nums[low-1])low++;
                    while(low<high && nums[high] == nums[high+1])high--;
                }
                
                else if(nums[low]+nums[high] >tar)high--;
                else low++;
                
            }
        }
        return ans;
    }
};





//Giving TLE but working 



// class Solution {

// public:
//     vector<vector<int>> threeSum(vector<int>& nums) {
        
//         sort(nums.begin(),nums.end());
//         vector<vector<int>> ans;
        
//         set<vector<int>> ds;
//         int n = nums.size();
//         int pre = INT_MIN;
//         for(int i=0;i<n;i++){
//             for(int j = i+1;j<n;j++){
//                 for(int k = j+1;k<n;k++){                    
//                     if(nums[i] + nums[j] + nums[k] == 0){
//                         ds.insert({nums[i],nums[j],nums[k]});
//                     }
//                 }
//             }
       
//         }
//         for( auto it : ds)
//             ans.push_back(it);
//         return ans;
//     }
// };


// class Solution {

// public:
//     vector<vector<int>> threeSum(vector<int>& nums) {
        
//         sort(nums.begin(),nums.end());
//         vector<vector<int>> ans;
        
//         set<vector<int>> ds;
//         unordered_map<int,int> mp;
//         int n = nums.size();
//         for(int i=0;i<n;i++)mp[nums[i]]++;
        
//         int pre = INT_MIN;
//         for(int i=0;i<n;i++){
//             mp[nums[i]]--;
//             for(int j = i+1;j<n;j++){
//                 mp[nums[j]]--;
                
//                 int k = -(nums[i]+nums[j]);
//                 if(mp.find(k) != mp.end() && mp[k]!=0){
//                     vector<int> temp(nums[i],nums[j],k);
//                     sort(temp.begin(),temp.end());
//                     ds.insert( temp);                        
//                 }                    
                
//                 mp[nums[j]]++;
                
//             }
//              mp[nums[i]]++;
       
//         }
//         for( auto it : ds)
//             ans.push_back(it);
//         return ans;
//     }
// };















