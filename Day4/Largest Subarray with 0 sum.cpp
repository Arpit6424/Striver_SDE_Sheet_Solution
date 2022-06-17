//Approach-1 Using 2-loops
//Time complexity O(n*n);
//Space complexity =O(1);
// class Solution{
//     public:
//     int maxLen(vector<int>&A, int n)
//     {   
//         // Your code here
//         int maxLen =0;
//      for(int i=0;i<n;i++){
//          int sum = 0;
  
//          for(int j = i;j<n;j++){
             
//              sum += A[j];
//              if(sum==0){
//                  int curLen = j-i+1;
//                  maxLen = max(maxLen , curLen);
//          }
//      }
//     }
//     return maxLen;
//     }
// };


//Approach-2 Using HashMap
//Time complexity O(n);
//Space complexity =O(n);

class Solution{
    public:
    int maxLen(vector<int>&A, int n)
    {   
        // Your code here
        unordered_map<int,int> mp;
        int sum =0;
        int maxLen =0;
        for(int i=0;i<n;i++){
            
            sum += A[i];
            if(sum ==0){
                maxLen =  i+1;
            }
            
            else{
                
                if(mp.find(sum) != mp.end()){
                    
                    maxLen = max(maxLen, i - mp[sum]);
                }
                else{
                    mp[sum] = i;
                }
                  
            }
        }
        return maxLen;
    }
};