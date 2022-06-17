// Approach-1 Sort the array and linearly traverse
//Time complexity O(nlogn + n);
//Space O(1);

// class Solution {
// public:
//     int longestConsecutive(vector<int>& nums) {
        
//         int  n = nums.size();
//         if(n==0 || n==1)return n;
        
//         sort(nums.begin(), nums.end());
        
//         int maxLen = 0;
//          int count = 0 ;
//         for(int i=0;i<n-1;i++){
           
//             if( nums[i] == nums[i+1])continue;
            
//             if( nums[i]+1 == nums[i+1] ){
//                 count++;
//                 maxLen = max(maxLen , count);
//             }
//             else count = 0;
            
//         }
        
//         return maxLen+1;
//     }
// };






// Approach-2  using hashSet
//Time complexity O(n + n + n);
//Space O(n);



class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        
      set<int> hashSet;
        for(int num : nums){ //O(n)
            hashSet.insert(num);
        }
        
        int longestStreak =0;
        
        for(int num: nums){ //O(n)
            
            if(!hashSet.count(num-1)){
                
                int curNum = num;
                int curStreak = 1;
                
                while(hashSet.count(curNum+1)){ //O(n)
                    curNum = curNum+1;
                    curStreak++;
                }
                longestStreak = max(longestStreak, curStreak);
            }
            
            
        }
        return longestStreak;
    }
};











