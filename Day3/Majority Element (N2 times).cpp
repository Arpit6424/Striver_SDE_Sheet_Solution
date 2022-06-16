// class Solution {
// public:
//     int majorityElement(vector<int>& nums) {
        
//          unordered_map<int, int> freq;
        
//         for(int i=0;i<nums.size();i++ ){
            
//             freq[nums[i]]++;
            
//         }
        
//         int maxFreq = 0;
//         int ans;
        
//         for(auto it : freq){
            
//            if(maxFreq<it.second){
//                ans =  it.first;
//                maxFreq = max(maxFreq , it.second);
//            }
//         }
//         return ans;
        
//     }
// };

//Moore`s Algorithm

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        
       int count = 0;
        int element;
        
        for(int i=0;i<nums.size();i++){
            
            if(count==0)element = nums[i];
            
            if(element == nums[i])count++;
            
            else count--;
        }
        
        return element;
        
    }
};