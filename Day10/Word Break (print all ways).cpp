#include<bits/stdc++.h>
void solve(int ind, string &s,string ds,unordered_set<string>& map,vector<string>& ans  ){
    
    if(ind==s.length()){
        ans.push_back(ds);
        return ;
    }
    
    for(int i=ind;i<s.length();i++){
       string temp = s.substr(ind,i-ind+1);
      if(map.find(temp) != map.end()){
            
            solve(i+1,s,ds+temp+" ",map,ans);
            
        }
        
    }
}



vector<string> wordBreak(string &s, vector<string> &dictionary)
{
    // Write your code here
    
    unordered_set<string> map;
    
    for(int ind=0;ind<dictionary.size();ind++)
        map.insert(dictionary[ind]);
    
    vector<string> ans;
    
    solve(0,s,"",map,ans);
    return ans;
    
    

}