#include<bits/stdc++.h>
bool isPossibleAllocation(vector<int>& positions , int n ,  int c, int mid){
    
    int cnt = 1;
    int lastplace = positions[0];
    for(int i=1;i<n;i++){        
        if(positions[i] - lastplace >=mid){
            cnt++;          
            lastplace = positions[i];
        }
    }
    
    if(cnt>=c)return true;
    return false;
        
}


int chessTournament(vector<int> positions , int n ,  int c){
	// Write your code here
    sort(positions.begin(),positions.end());
    int low = 1;
    int high =positions[n-1]-positions[0];
    int ans;
    while(low<=high){
        int mid = (low+high)>>1;
        if(isPossibleAllocation(positions,n,c,mid)){
            ans = mid;
            low  =mid+1;
       
        }
        else
            high = mid-1;
    }
    
    return ans;
}