// class Solution {
// public:
//     string reverseWords(string s) {
//         s += " ";
//         stack<string> st;
//         string str = ""; 
        
//        for(int i=0;i<=s.length();i++){
           
//            if(  s[i]== ' '){
               
//                if(str != "")
//                st.push(str);
//                str = "";
//            }
           
//            else str += s[i];
//        }
//         string ans = "";
        
//         while(!st.empty()){
            
//             if(st.size()==1) ans += st.top();
//             else ans += st.top() + " ";
          
//             st.pop();
//         }
//         return ans;
//     }
// };









class Solution {
public:
    string reverseWords(string s) {
        int n = s.size();
        string temp = "";
        string ans = "";
        
        for(int i=0;i<=n;i++){
            
            if(i<n && s[i] != ' ')  temp += s[i];               
            
            else if(temp != ""){
                
                if(ans != "") ans = temp + " " + ans;
                else ans = temp;
                temp = "";
            }
        }
            
        return ans;
        

    }
};














