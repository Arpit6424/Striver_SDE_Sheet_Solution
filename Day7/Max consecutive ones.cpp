class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        
        int maxCons =0;
        int curmax = 0;

        for(int i=0;i< nums.size();i++){
            
            if(nums[i]==1)curmax++;
            else curmax =0;
            
           if(curmax>maxCons)maxCons = curmax;
          
        }
        return maxCons;
        
    }
};