// class Solution {
// public:
//     int maxSubArray(vector<int>& nums) {
        
//         int maxSum = INT_MIN;
//         int curSum=0;
//         for(int ind=0;ind<nums.size();ind++){
            
//             curSum += nums[ind];
            
//             if(curSum>maxSum) maxSum = curSum; 
//             if(curSum <0)  curSum = 0;
           
               
            
//         }
//         return maxSum;
        
//     }
// };




//Divide and Conquer


class Solution {
    
    int crossMax(int l ,int h, vector<int> &nums){
         int mid = (l+h)/2;
        
        
        int leftS_max=INT_MIN;
        int sum =0;       
        
        for(int i =mid;i>=l;i-- ){
            
            sum = sum + nums[i];
            if(sum>leftS_max)leftS_max=sum;
        }
        
        
        int rightS_max=INT_MIN;
        sum =0;  
        
         for(int i =mid+1;i<=h;i++ ){
            
            sum = sum + nums[i];
            if(sum>rightS_max)rightS_max=sum;
        }
        
        return  max(   leftS_max + rightS_max , max(leftS_max , rightS_max));
        
    }
    
    
    
    int solve(int l, int h, vector<int>& nums){
        
        if(l==h)return nums[l];
        
        int mid = (l+h)/2;
        
        
        return max(  solve(l,mid,nums),
                   max( solve(mid+1,h,nums), crossMax(l,h,nums) ) );
        
    }
public:
    int maxSubArray(vector<int>& nums) {
        
     int n= nums.size();
        
        return solve(0,n-1,nums);
        
    }
};