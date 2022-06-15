class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        
        
        int numsLen = nums.size(), k,l;
        
        for( k=numsLen-2; k>=0 ;k--){
            
            if(nums[k] < nums[k+1])
                break;
        }
      
        if(k < 0){
            reverse(nums.begin(),nums.end());
      
        }
        else{
            
            for(l=numsLen-1;l>k;l--){
                
                if(nums[k]<nums[l])break;
            }
            
            swap(nums[l],nums[k]);
            reverse(nums.begin()+k+1, nums.end());
        }
        
        
        
    }
};