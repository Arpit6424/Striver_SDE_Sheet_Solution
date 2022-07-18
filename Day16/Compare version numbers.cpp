class Solution {
public:
    int compareVersion(string version1, string version2) {
        
        
        string no1 = "";
        string no2 = "";
        
        int i=0,j=0;
        
        while(i<version1.length() || j<version2.length()){
        
        while(i<version1.length()){
            if(version1[i]=='.')break;
            no1 += version1[i];
            i++;
        }
        while(j<version2.length()){
            if(version2[j]=='.')break;
            no2 += version2[j];
            j++;
        }

        if( stoi(no1) > stoi(no2) )return 1;
        if( stoi(no1) < stoi(no2)  )return -1;
        
        no1 = "0";
        no2 = "0";
            i++,j++;
        }

        return 0;
        
    }
};