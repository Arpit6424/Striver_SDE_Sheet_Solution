class Solution {
    
    bool isPalindrom(string &s, int st, int end){
        
        while(st<=end){
            
            if(s[st++]!=s[end--])return false;
        }
        return true;
    }
    
    void solve(int ind, string &s, vector<string> &temp, vector<vector<string>> &ans){
        
        if(ind == s.length()){
            ans.push_back(temp);
            return ;
        }
            
       for(int i=ind;i<s.length();i++){
           
           if(isPalindrom(s ,ind, i)){
               temp.push_back(s.substr(ind,i-ind+1));
               solve(i+1,s,temp,ans);
               temp.pop_back();
               
           }
       }
            
    }
    
public:
    vector<vector<string>> partition(string s) {
        
        
        
        
        vector<vector<string>> ans;
        vector<string> temp;
        
        solve(0, s,temp, ans);
        return ans;
        
    }
};