// class Solution {
// public:
//     string countAndSay(int n) {

//         int j =1;
        
//         string ans ="";
//         string temp = "1";
//         while(j<n){
           
//             int len = temp.size();
//             int i=0;
//             int cnt = 1;
//             while(i<len){

//                 if(i+1<len && temp[i] == temp[i+1]){
//                     cnt++,i++;
//                 }
//                 else{
//                     ans = ans +  to_string(cnt) + temp[i];
//                     cnt = 1;
//                     i++;
//                 }
//             }
//             temp = ans;
//             ans = "";
//             j++;
            
//         }
//         return temp;
//     }
// };










class Solution {
     
    string solve(int n){
        
        if(n==1)return "1";
        
        string temp = solve(n-1);
        
        string ans = "";
        int cnt = 1;
        int len = temp.length();
  
        for(int i=0;i<len;i++){

            if(i+1<len && temp[i] == temp[i+1])
                cnt++;
            
            else{
                ans = ans +  to_string(cnt) + temp[i];
                cnt = 1;

            }
        }
        return ans;
        
    }
public:
    string countAndSay(int n) {
        return solve(n);
    }
};























