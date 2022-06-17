
/***********************************************/
/**********************************************/


//Approach-1 Two pointer approach 
//Time Complexity O(n + n);//left right pointer 
//space complexity O(n)



class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        
        
        int  n = s.size();
        if(n==0 || n==1)return n;
        
        unordered_set<int> map;
        
        int maxLen = 0;
    
        int left=0;
        for(int right=0;right<n;right++){
            
            
            if(map.find(s[right])!= map.end()){
                
              while(left<right &&  map.find(s[right]) != map.end()){
                  map.erase(s[left]);
                      left++;
              }
            }
        
                map.insert(s[right]);
              maxLen = max(maxLen, right-left+1);
 
        }
       
      \
        
        return maxLen;
        
    }
};


/***********************************************/
/**********************************************/




/***********************************************/
/**********************************************/



//Approach-1 Two pointer approach but optimise way 
//Time Complexity O(n );
//space complexity O(n)


// class Solution {
// public:
//     int lengthOfLongestSubstring(string s) {
        
        
//         int  n = s.size();
//         if(n==0 || n==1)return n;
        
//         unordered_map<char , int> map;
        
//         int maxLen = 0;
    
//         int left=0;
        
//         for(int right=0;right<n;right++){
            
//             if(map.find(s[right]) != map.end()){
//                left = max(map[s[right]]+1 ,left);
//             }
            
//             map[s[right]] = right;
            
//             maxLen= max(maxLen, right - left +1);
//         }

//         return maxLen;
//     }
// };






/***********************************************/
/**********************************************/










