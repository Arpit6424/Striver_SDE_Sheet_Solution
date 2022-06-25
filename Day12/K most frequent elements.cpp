class compare{
    public:
    bool operator()(pair<int,int> &a,pair<int,int> &b){
        
        return a.second > b.second;       
        
    }
};

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        
                   //pair<element,frequency>
        priority_queue<pair<int, int> , vector<pair<int, int>> , compare> minheap;
        
        unordered_map<int,int> map;
        
        for(int i=0;i<nums.size();i++){
           map[nums[i]]++;
        }
        
        for(auto it : map){
            
            if(minheap.size()<k)minheap.push({it.first,it.second});
            
            else if(minheap.top().second < it.second){
                minheap.pop();
                minheap.push({it.first,it.second});
                
            }
        }
        
        vector<int> ans(k);
        for(int i=k-1;i>=0;i--){
            ans[i] = minheap.top().first;
            minheap.pop();
        }
        return ans;
        
    }
};