
// Brute Force Approach
//Time Complexity o(n*n) gives TLE
//space o(1)

// class Solution {
// public:
//     int reversePairs(vector<int>& nums) {
        
//         int count =0;
        
//         int n = nums.size();
//         for(int i=0;i<n-1;i++){
//             for(int j=i+1;j<n;j++){
                
//                 if(nums[i]> 2LL * nums[j])count++;
//             }
//         }
//         return count;
        
//     }
// };



//Optimal approach
//Using merge sort
//Time complexity o(nlogn + n );
//Space complexity O(n)
class Solution {
    
    int merge(int low, int mid, int high, vector<int> &nums){
        
         int count =0;
        int j = mid+1;
        
        for(int i=low;i<=mid;i++){
            
            while(j<=high && nums[i]>2LL * nums[j]){
                j++;
            }
            count += (j -(mid+1));
            
        }
        
        int n1 = mid-low+1;
        int n2 = high - mid;
        
        int arr1[n1];
        int arr2[n2];
        
        for(int i=0;i<n1;i++)arr1[i] = nums[low+i];
        for(int j=0;j<n2;j++)arr2[j] = nums[mid+1+j];
        
        int i=0; j=0;int k=low;
        while(i<n1 && j<n2){
            
            
            if(arr1[i]<=arr2[j])nums[k++] = arr1[i++];
            else {
                 
                nums[k++] = arr2[j++];
            }
        }
        
        while(i<n1) nums[k++] = arr1[i++];
        while(j<n2) nums[k++] = arr2[j++];
        
        return count;
        
        
        
        
    }
    
    
    int solve(int low,int high, vector<int>& nums){
        
        int count = 0;
        
        if(low<high){
            
            int mid = (low+high)/2;
            
            count +=  solve(low,mid,nums);
            count +=  solve(mid+1,high ,nums);
            
            count += merge(low,mid, high, nums);
            
            
        }
        return count;
    }
        
public:
    int reversePairs(vector<int>& nums) {
        
       
         return solve(0,nums.size()-1,nums);

    }
};