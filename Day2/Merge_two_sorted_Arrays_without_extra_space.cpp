class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        
        
        int ind1 = m-1;
        int ind2 = n-1;
        int ind3 = n+m-1;
        
        
        while(ind1>=0 && ind2>=0){
            
            if(nums1[ind1] <=nums2[ind2]){
                
                nums1[ind3] = nums2[ind2];
                ind2--;
                ind3--;
            }
            else{
                
                nums1[ind3] = nums1[ind1];
                ind1--;
                ind3--;
            }
            
            
            
        }
        
        while(ind2>=0){
            
            nums1[ind3] = nums2[ind2];
                ind2--;
                ind3--;
        }
        
    }
};