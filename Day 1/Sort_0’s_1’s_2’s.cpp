class Solution {
public:
    void sortColors(vector<int>& nums) {
        
        int n = nums.size();
        
        int i=0;
        int j=n-1;
        
        int ind=0;
        while(ind<=j){
            
            if(nums[ind]==0){
                swap(nums[i],nums[ind]);
                ind++;
                i++;
            }
            else if(nums[ind]==2){
                swap(nums[ind],nums[j]);
                j--;
            }
            else{
                ind++;
            }
        }
        
    }
};