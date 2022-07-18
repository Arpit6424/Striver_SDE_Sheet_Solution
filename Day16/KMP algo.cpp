// class Solution {
// public:
//     int strStr(string haystack, string needle) {
        
//         int n = haystack.size();
//         int m = needle.size();
        
//         for(int i=0;i<n;i++){
                
//             if(haystack[i]==needle[0]){                
//                 int j =0;              
//                 while(j<m && haystack[i+j]==needle[j]){                    
//                     j++;
//                 }                
//                 if(j==m)return i;    

//             }
//         }        
//         return -1;
//     }
// };








// class Solution {
    
//     int Rabin_Karp(string &text, string &pattern){
    
//     int n = text.length();
//     int m = pattern.length();
    
//     int hashCode =0;
//     for(int i=0;i<m;i++){
//         hashCode += pattern[i] - 'a';
//     }
    
//     int curhashValue = 0;
//     for(int i = 0;i<m;i++){
//         curhashValue += text[i] - 'a';
//     }
    
    
//     for(int i=0;i<=n-m;i++){        
//         if(hashCode==curhashValue){
//             int j;
//             for(j=0;j<m;j++)
//                 if(pattern[j]!=text[i+j])break;            
//             if(j==m)return i;
//         }       
        
//         if(i<n-m){
//             curhashValue = curhashValue -( text[i]-'a') + text[i+m] - 'a';
//         }
//     }
//    return -1;    
// }
    
// public:
//     int strStr(string haystack, string needle) {        
//         return Rabin_Karp(haystack,needle);    
//     }
// };



// class Solution {
    
    
//     int Z_algorithm(string &text, string &pattern){
        

//         string str = pattern + "$" + text;
//         int str_len = str.length();
//         int Zarray[str_len];
//         Zarray[0] =0;
        
//         int L=0,R=0,i;
//         for(i=1;i<str_len;i++){            
//             if(i>R){                
//                 R=L=i;
//                 while(R<str_len && str[R-L] == str[R])R++;
//                 Zarray[i] = R-L;
//                 R--;
//             }
//             else{                
//                 int idx = i-L;
//                 if(Zarray[idx] < R-i+1)
//                     Zarray[i] = Zarray[idx];
//                 else{
//                     L = i;
//                     while(R<str_len && str[R-L] == str[R])R++;
//                     Zarray[i] = R-L;
//                     R--;
//                 }               
//             }
//         }
        
//         for(int i=0;i<str_len;i++)         
//             if(Zarray[i]==pattern.length())return i-pattern.length()-1;
        
            
//         return -1;
//     }
    
// public:
//     int strStr(string haystack, string needle) {
        
//              return Z_algorithm(haystack,needle);   

//     }
// };


class Solution {    
    
    void computeLPSArray(string &pattern , int arr[], int patt_len){
        arr[0] = 0;
        int index = 0, i=1;        
        while(i<patt_len){            
            if(pattern[index] == pattern[i]){                
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
    }
    
    
    int Knuth_Morris_Pratt(string &text, string &pattern){        
        int patt_len = pattern.length();
        int text_len = text.length();        
        int arr[patt_len];         
        
        computeLPSArray(pattern ,arr,patt_len);        
        int i=0,j=0;
        while(i<text_len){           
            
            if(text[i] == pattern[j]){
                i++,j++;             
            }              
            
            if(j==patt_len)return i-j;            
            else if(i<text_len && text[i] != pattern[j]) {                
                if(j !=0)
                    j = arr[j-1];
                else
                    i++;
            }
        }
        return -1;        
    }
    
public:
    int strStr(string haystack, string needle) {      
                
         return Knuth_Morris_Pratt(haystack, needle);

    }
};





