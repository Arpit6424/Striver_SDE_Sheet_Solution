/******************************************************************************/
/*****************************************************************************/
//Approach-1 find max, min array then calculate each index contains how much water
//Time complexity O(n) + O(n) + O(n)
//Space Complexity O(n) + O(n);


// class Solution {
// public:
//     int trap(vector<int>& height) {
        
//         int n = height.size();
//         vector<int> pre(n),suff(n);
        
//         pre[0] = height[0];        
//         for(int i=1;i<n;i++)
//             pre[i] = max(pre[i-1] , height[i]);
        
        
//         suff[n-1] = height[n-1];
//         for(int i = n-2;i>=0;i--)
//             suff[i] = max(suff[i+1], height[i]);
        
        
//         int countWater = 0;
//         for(int i=0;i<n;i++ )            
//             countWater += min(pre[i],suff[i]) - height[i];
        
//         return countWater;
        
//     }
// };


/******************************************************************************/
/*****************************************************************************/
//Approach-2 Two pointer approach
//Time complexity O(n) 
//Space Complexity O(1)



class Solution {
public:
    int trap(vector<int>& height) {
        
        int waterCount =0;
        int low =0,high = height.size()-1;
        int lmax = 0,rmax =0;
        
        while(low<=high){
            
            if(height[low]<=height[high]){
                
                if(height[low] < lmax)
                    waterCount += lmax - height[low];
                else
                    lmax = max(lmax, height[low]);
                low++;
            }
            else{
                
                if(height[high] < rmax)
                    waterCount += rmax - height[high];
                else
                    rmax = max(rmax, height[high]);
                high--;
                
            }            
                       
        }
        return waterCount;
     
    }
};