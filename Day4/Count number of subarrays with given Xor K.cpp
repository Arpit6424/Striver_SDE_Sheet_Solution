/****************************/
/***************************/
// Approach-1 Using 2 loops
// Time complexity O(n*n);
//Space complexity O(1);


#include <bits/stdc++.h> 
// int subarraysXor(vector<int> &A, int x)
// {
//     int n = A.size();
//          int ans =0;
//      for(int i=0;i<n;i++){
//          int sum = 0;
  
//          for(int j = i;j<n;j++){
             
//              sum ^= A[j];
//              if(sum==x){
//                  ans++;
//          }
//      }
//     }
//     return ans;
// }

/****************************/
/***************************/

// Approach-2 Using Hash_map
// Time complexity O(n);
//Space complexity O(n);

#include <bits/stdc++.h> 
int subarraysXor(vector<int> &A, int x)
{
   
    int n = A.size();
    int xorr =0;
    int cnt=0;
    unordered_map<int,int> map;
    
    for(int it : A){
        
        xorr ^= it;
        if(xorr==x)cnt++;
        
        if(map.find(xorr^x) != map.end())
            cnt += map[xorr^x];
        
        map[xorr]++;
    }
       return cnt;
}




