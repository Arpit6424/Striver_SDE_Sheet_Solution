/*-----------------------------*/
/*----------------------------*/

//Approach-1 (Brute force) Simply Linearly  Traverse
// Time Complexity = n*m
//space 0(1);


// class Solution {
// public:
//     bool searchMatrix(vector<vector<int>>& matrix, int target) {
        
//         int n = matrix.size();
//         int m = matrix[0].size();
//         for(int i=0;i<n;i++){
//             for(int j=0;j<m;j++){
                
//                 if(matrix[i][j]==target)return true;
//             }
//         }
//         return false;
        
//     }
// };


/*-----------------------------*/
/*----------------------------*/


//Approach-2 Binary Search

// Time Complexity = log(n*m)
//space 0(1);

// class Solution {
// public:
//     bool searchMatrix(vector<vector<int>>& matrix, int target) {
        
//     int n = matrix.size();
//     int m = matrix[0].size();
        
//     int low =0;
//     int high = (n*m)-1;
//     int mid = (low + high)/2;
        
//     while(low<=high){
        
//         int element = matrix[mid/m][mid%m];
        
//         if(element==target)return true;
        
//         if(element>target)high = mid-1;
        
//         else low = mid +1;
        
//         mid = (low + high)/2;
//     }
//     return false;
        
    
        
//     }
// };

/*-----------------------------*/
/*----------------------------*/

//Approach-3 Binary Tree pattern search
// Time Complexity =log(n*m)
//space 0(1);

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        
    int n = matrix.size();
    int m = matrix[0].size();
        
    int i = 0;
    int j = m-1;
    while(i < n && j>=0 ){
        
        int element  = matrix[i][j];
        
        if(element==target)return true;
        
        if(element<target){
            i++;
        }
        else {
            j--;
        }
    }
    return false;
        
    
        
    }
};

/*-----------------------------*/
/*----------------------------*/



