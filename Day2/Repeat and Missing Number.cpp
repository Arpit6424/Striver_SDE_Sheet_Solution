#include <bits/stdc++.h> 

pair<int,int> missingAndRepeating(vector<int> &A, int n)
{
  unordered_map<int,int> freq;
    int repeatELe;
    int misElement;
    
    for(int i=0;i<A.size();i++){
        
        freq[A[i]]++;        
    }
    
    for(int i=1;i<=A.size();i++){
        
        if(freq.find(i)==freq.end())misElement = i;
        if(freq[i]==2)repeatELe = i;
    }
    
    
    return make_pair(misElement,repeatELe);
	
}
