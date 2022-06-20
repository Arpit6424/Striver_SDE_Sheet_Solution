#include<bits/stdc++.h>
 static bool sortbysec(const pair<int,int> &a, const pair<int,int> &b){
         return (a.second < b.second);
        
    }

int maximumActivities(vector<int> &start, vector<int> &end) {
    // Write your code here.
    int n = start.size();
       vector<pair<int,int>> time(n);
        
        for(int i=0;i<n;i++){
            time[i] = make_pair(start[i],end[i]);
        }
        
        
        sort(time.begin(),time.end(),sortbysec);
        
        int count_meeting =0;
        int prevEnd =-1;
        
         for(auto it : time){
            
            if(it.first >= prevEnd){
                count_meeting++;
                prevEnd = it.second;
                }
                
                
            }
            return count_meeting;
}