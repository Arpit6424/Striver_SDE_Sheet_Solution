class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        
        sort(nums.begin(),nums.end());
        
        vector<vector<int>> ans;
         
        
        int n = nums.size();
        for(int i=0;i<n;i++){
             long long target_3 = target - nums[i];
            for(int j=i+1;j<n;j++){
                
                 long long target_2 = target_3 - nums[j];
                 
                int x = j+1;
                int y = n-1;                  
                while(x<y){
                    
                    int sum = nums[x] + nums[y];
                   
                    
                    if(sum == target_2){
                          vector<int> temp(4);
                        temp[0] = nums[i];
                        temp[1] = nums[j];
                        temp[2] = nums[x];
                        temp[3] = nums[y];
                        ans.push_back(temp);
                        
                        while(x<y && temp[2] == nums[x])x++;
                        while(x<y && temp[3] == nums[y])y--;

                    }
                    
                    else if(sum > target_2)y--;
                    else x++;
                }
                
                while(j + 1 < n && nums[j + 1] == nums[j]) ++j;
                
            }
            while (i + 1 < n && nums[i + 1] == nums[i]) ++i;
        }
        return ans;
    }
};









