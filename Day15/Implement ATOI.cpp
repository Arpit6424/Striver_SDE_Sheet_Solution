class Solution {
public:
    int myAtoi(string s) {
        
          int ans=0;
        bool negative=false;
        int i=0,n=s.size();
        while(i<n && s[i]==' ') i++; // leading spaces
		
        if(i<n && s[i]=='-' || s[i]=='+'){  // to check result will be negative or not
            if(s[i]=='-') negative=true;
            i++;
        }
		
        while(i<n && isdigit(s[i])){
            if(INT_MAX/10<ans || INT_MAX-ans*10<(s[i]-'0')){ // checking if result will go out of range
                if(negative) return INT_MIN;
                return INT_MAX;
            }
            ans=ans*10+(s[i]-'0');
            i++;
        }
        if(negative)
            ans*=-1;
        return ans;
        
    }
};