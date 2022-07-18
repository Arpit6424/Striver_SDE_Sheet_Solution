// class Solution {
// public:
//     int maxProduct(vector<int>& nums) {        
        
//         int maxAns =INT_MIN;
        
//         for(int i=0;i<nums.size();i++){
//             int cur =1;
//             for(int j=i;j<nums.size();j++){                
//                 cur = cur*nums[j];
//                 maxAns = max(maxAns , cur);                
//             }
//         }        
//         return maxAns;        
//     }
// };




// class Solution {
// public:
//     int maxProduct(vector<int>& nums) {        
        
//         int maxAns = nums[0];
//         int ma = maxAns;
//         int mi = maxAns;
        
//         for(int i=1;i<nums.size();i++){
            
//             if(nums[i]<0)swap(ma,mi);
            
//             ma = max(nums[i],ma*nums[i]);
//             mi = min(nums[i] ,mi*nums[i]);
//             maxAns = max(maxAns,ma);
//         }
//         return maxAns;
//     }
// };












class Solution {
public:
    int maxProduct(vector<int>& nums) {        
        
        int maxAns =INT_MIN;
        
        int cur =1;
        for(int i=0;i<nums.size();i++){                           
            cur = cur*nums[i];
            maxAns = max(maxAns , cur);   
            if(nums[i]==0)cur = 1;
            
        }        
        cur =1;
        for(int i=nums.size()-1;i>=0;i--){                           
            cur = cur*nums[i];
            maxAns = max(maxAns , cur);   
            if(nums[i]==0)cur = 1;

        }
         
        return maxAns;
        

    }
};