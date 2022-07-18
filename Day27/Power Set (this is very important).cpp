#include<bits/stdc++.h>
vector<vector<int>> pwset(vector<int>v)
{
    //Write your code here
    int n = v.size();
    vector<vector<int>> ans;
    for(int num=0;num<(1<<n);num++){        
        vector<int> subset;
        for(int i=0;i<n;i++){
            
            if(num & (1<<i)){
               subset.push_back(v[i]);
            }
        }
        ans.push_back(subset);
    }
    sort(ans.begin(),ans.end());
    return ans;
}