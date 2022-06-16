// class Solution {
// public:
//     vector<int> majorityElement(vector<int>& nums) {
        
        int n = nums.size();
        unordered_map<int, int> freq;
        
        for(int i=0;i<nums.size();i++ )
            freq[nums[i]]++;

          
        vector<int> ans;

        for(auto it : freq)
            if(it.second>n/3)ans.push_back(it.first);
           

         return ans;

     }
       
        

// };

//Solution 2: Optimal Solution (Extended Boyer Moore’s Voting Algorithm)

class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        
        int n = nums.size();
        vector<int> ans;
        
        int candidate1 = INT_MIN;
        int candidate2 = INT_MIN;
        int count1 = 0;
        int count2 =0;
        
        for(int i=0;i<n;i++){
            int element = nums[i];
            
            if(element==candidate1)count1++;
                
            else if(element== candidate2)count2++;
            
            else if(count1==0) candidate1 = element , count1 = 1 ;
            
            else if(count2 ==0)candidate2 = element , count2 = 1;
            
            else
                count1--,count2--;
             
            
        }
        
        
        count1 = 0, count2 =0;
        
        for(int i=0;i<n;i++){
            int element = nums[i];
            
            if(element==candidate1)count1++;
            if(element==candidate2)count2++;
        }
        
        
        if(count1>(n/3))ans.push_back(candidate1);
        if(count2>(n/3))ans.push_back(candidate2);
        
        return ans;
    
    }
       
        

};