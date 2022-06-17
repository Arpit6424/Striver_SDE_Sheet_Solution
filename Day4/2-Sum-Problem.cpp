//Brute Force run two loops
//time complexity O(n*n);
//Space complexity O(n) //for ans vector required considered O(1);



// class Solution {
// public:
//     vector<int> twoSum(vector<int>& nums, int target) {
        
//         int n = nums.size();
//         bool flag = false;
//         vector<int> ans;
//         for(int i=0;i<n-1;i++){
//             for(int j=i+1;j<n;j++){
                
//                 if(nums[i] + nums[j]==target){
//                     ans.push_back(i);
//                     ans.push_back(j);
//                      flag = true;
//                     break;
//                 }
//             }
//             if(flag)break;
//         }
//         return ans;
//     }
// };


/********************************/
 /******************************/


//Approach-2  Using Two pointer 
//Time complexity O(nlogn + n)
//space complexity O(n + n)

// class Solution {
// public:
//     vector<int> twoSum(vector<int>& nums, int target) {
        
//         int n = nums.size();
//         vector<int> ans,temp;
        
//         temp = nums;
        
        
//         sort(temp.begin(),temp.end());
        
//         int element1,element2;
        
//         int i=0,j = n-1;
        
//         while(i<j){
            
//             if(temp[i]+temp[j]==target){
//                 element1 = temp[i];
//                 element2 = temp[j];
//                 break;
//             }
            
//             else if(temp[i]+temp[j] > target)j--;
//             else i++;            
            
//         }
        
        
//         for(int i=0;i<n;i++){
            
//             if(nums[i]==element1 || nums[i]==element2 )
//                 ans.push_back(i);
//         }
        
//         return ans;
        
        
        
//     }
// };


    
    
/********************************/
 /******************************/
    
/*
   Approach-3 Using hash Map
   time complexity O(n);
   Space complexity O(n + n );
*/
    

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
     
        int n = nums.size();
        unordered_map<int,int> map;
        
        vector<int> ans;
        
        for(int i=0;i<n;i++){
            
            if(map.find(target - nums[i]) != map.end()){
                ans.push_back(i);
                ans.push_back(map[target - nums[i]]);
                break;
            }
            
            map[nums[i]] = i;
            
        }
        
        return ans;
    }
};








