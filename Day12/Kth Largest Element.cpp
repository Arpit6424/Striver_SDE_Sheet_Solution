// Approach-1 using maxHeap put all element in heap then return k top element
// Time Complexity O(nlogn+ k);
// Space complexity O(n)

// class Solution {
// public:
//     int findKthLargest(vector<int>& nums, int k) {
        
//         priority_queue<int> pq;
        
//         for(int i=0;i<nums.size();i++){
//             pq.push(nums[i]);
//         }
        
//         while(--k){         
//             pq.pop();
          
//         }
        
//         return pq.top();
//     }
// };






// Approach-2 using minHeap in smarter way put k element in heap then check if element is bigger than top element of heap then remove top ans push the element in the end you have k biggest element in minheap ans our is top element of heap
// Time Complexity O(nlogk);
// Space complexity O(k)



class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        
        priority_queue<int,vector<int> ,greater<int>> pq;
        
        for(int i=0;i<nums.size();i++){
            
            if(pq.size()<k )
               pq.push(nums[i]);
            
            else if(pq.top() < nums[i]){
                pq.pop();
                pq.push(nums[i]);
            }
                
                
            
        
        }
        
        return pq.top();
    }
};



//Approach-3 using quicksort
// Time Complexity: O(n)
// Space Complexity: O(1)

// class Solution {
    
//     int partition(int low, int high,vector<int>& nums){
        
        
//         int pivot = nums[low];
//         int i = low;
//         int j= high;
        
//         while(i<j){
            
//             while(i<high && pivot>=nums[i])i++;
            
//             while(low<j && pivot<nums[j])j--;
            
//             if(i<j)swap(nums[i],nums[j]);
//         }
//         swap(nums[low],nums[j]);
//         return j;
//     }
    
    
//     int quickSort(int low, int high,vector<int>& nums,int n, int k){
        
//         k = n-k;
        
//         while(low<high){
            
//             int pivotInd = partition(low,high,nums);
            
//             if(pivotInd==k)break;
            
//             else if(pivotInd>k)high = pivotInd-1;
//             else low = pivotInd+1; 
//         }
        
//         return nums[k];
//     }
    
// public:
//     int findKthLargest(vector<int>& nums, int k) {
//         int n= nums.size();
        
//        return quickSort(0,n-1,nums,n,k);
//     }
// };