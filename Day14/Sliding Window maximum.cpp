// Approach-1 using two loop first for n and second for k
//Time complexity O(n*k);
// Space complexity O(1) ,except ans vector


// class Solution {
// public:
//     vector<int> maxSlidingWindow(vector<int>& nums, int k) {
//         vector<int> ans;
//         int n= nums.size();
    
//         for(int i=k-1;i<n;i++){
            
//             int maxi = INT_MIN;
//             int j= i;
//             int t = k;
//             while(t--){
//                 maxi = max(maxi, nums[j--]);
//             }
//             ans.push_back(maxi);
            
            
//         }
//         return ans;
        
//     }
// };

// Approach-2 using prority queue
//Time complexity O(n +n);
// Space complexity O(k)
// class Solution {
// public:
//     vector<int> maxSlidingWindow(vector<int>& nums, int k) {
//         vector<int> ans;
//         int n= nums.size();        
//                      //value,index
//         priority_queue<pair<int,int>> q;
        
//         for(int i=0;i<k;i++)
//             q.push({nums[i],i});        
//         ans.push_back(q.top().first);
        
//         for(int i = k;i<n;i++){       
           
//             while(q.size()>k && q.top().second <= i-k ){
//                 q.pop();
//             }            
//             q.push_back({nums[i],i});
//             ans.push_back(q.top().first);   
//         }      
//         -      
//         return ans;
        
//     }
};


// Approach-3 using deque
//Time complexity O(n + n);
// Space complexity O(k)



class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        

        int n= nums.size();
                
        vector<int> ans;
        
        deque<int> dq;
        for(int i=0;i<n;i++){
            
            if(!dq.empty() && dq.front() == i-k)dq.pop_front();
            
            while(!dq.empty() && nums[dq.back()] <= nums[i])dq.pop_back();
            
            dq.push_back(i);
            
            if(i >= k-1 )ans.push_back(nums[dq.front()]);
        }
     
        return ans;
        

        
    }
};


