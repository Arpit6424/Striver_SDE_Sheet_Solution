#include<bits/stdc++.h>

vector<int> maxMinWindow(vector<int> nums, int n) {
    // Write your code here.
           vector<int> res;
    for(int k=1;k<=n;k++){      
         int maxi = INT_MIN;  
        deque<int> dq;
        for(int i=0;i<n;i++){
            
            if(!dq.empty() && dq.front() == i-k)dq.pop_front();
            
            while(!dq.empty() && nums[dq.back()] >= nums[i])dq.pop_back();
            
            dq.push_back(i);
            
            if(i >= k-1 && maxi < nums[dq.front()])maxi =nums[dq.front()] ;
        }
     
         res.push_back(maxi);
            }
    return res;
}