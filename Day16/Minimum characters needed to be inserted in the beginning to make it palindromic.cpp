
    int computeLPSArray(string text ){
        int n = text.length();
        string str = text;
        reverse(str.begin(),str.end());
        
        str = text + "$" + str;
        int len = str.length();
        
        
        int arr[len];
        arr[0] = 0;
        int index = 0, i=1;        
        while(i<len){            
            if(str[index] == str[i]){                
                index++;
                arr[i] = index;
                i++;
            }
            else{                
                if(index != 0)                    
                    index = arr[index-1];
                else{
                    arr[i] = 0;
                    i++;
                }                   
            }
        }

        return n-arr[len-1];
    }
int Solution::solve(string A) {
   return  computeLPSArray(A);
}
