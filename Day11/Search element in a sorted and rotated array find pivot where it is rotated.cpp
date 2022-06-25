// class Solution {
// public:
//     int search(vector<int>& nums, int target) {
        
//         int ans = -1;
//         for(int i=0;i<nums.size();i++){
//             if(nums[i]==target){
//                 ans = i;
//                 break;
//             }
//         }
//         return ans;
        
//     }
// };







class Solution {
public:
    int search(vector<int>& nums, int target) {
        
        int ans = -1;
        int low = 0;
        int high =  nums.size()-1;
        
        while(low<=high){
            
            int mid = (low+high)/2;
            
            if(nums[mid]==target){
                ans = mid;
                break;
            }
            
            if(nums[low] <=nums[mid]){
                if(nums[low]<=target && target<=nums[mid])high = mid-1;
                else low = mid+1;
                
              }
              else{
                  if(nums[mid]<=target && target<=nums[high])low = mid+1;
                  else high = mid-1;
              }
                
                
            
        }
        return ans;
        
        
    }
};