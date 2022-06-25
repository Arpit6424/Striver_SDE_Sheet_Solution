//Approach-1 create new array then find median
//Time complexity O(n+m);
//Space complexity O(n+m);
// class Solution {
    
//     void mergeTwoarray(vector<int>& nums1, vector<int>& nums2,vector<int>& arr,int n, int m){        
        
//         int i=0,j=0,k=0;
        
//         while(i<n && j<m){            
//             if(nums1[i]<=nums2[j])arr[k++] = nums1[i++];
//             else arr[k++] = nums2[j++];
//         }
        
//         while(i<n)arr[k++] = nums1[i++];
//         while(j<m)arr[k++] = nums2[j++];
        
//     }
    
    
    
// public:
//     double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
//         int n = nums1.size();
//         int m = nums2.size();
        
//         vector<int> arr(n+m);
        
//         mergeTwoarray(nums1,nums2,arr,n,m);
        
//         if((m+n)%2==1)
//             return arr[(n+m)/2]*1.0;
//         else 
//             return (arr[(n+m)/2] + arr[(n+m)/2 -1])/2.0;
        
//     }
// };






//Approach-2  using binary search
//Time complexity O(lom(n+m));
//Space complexity O(1);


class Solution {
  
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        
        
        
        int n = nums1.size();
        int m = nums2.size();
        
        if(n>m)return  findMedianSortedArrays(nums2,nums1);
        
        int low = 0;
        int high = n;
        
        while(low<=high){            
                      
            int cut1 = (low+high)>>1;
            int cut2 = ((n+m+1)>>1) - cut1;
            
            int left1 = cut1==0?INT_MIN : nums1[cut1-1];
            int left2 = cut2==0 ? INT_MIN : nums2[cut2-1];
            
            int right1 = cut1==n ? INT_MAX : nums1[cut1];
            int right2 = cut2==m ? INT_MAX : nums2[cut2];
            
            
            if(left1 <= right2 && left2 <= right1){
                
                if((n+m)%2==0) return (max(left1,left2) + min(right1,right2))/2.0;
                    
                else return max(left1,left2);
                    
            }
            
            else if(left1 > right2) high = cut1-1;
            else low = cut1+1;
                
        }
        return 0.0;
        
    }
};











