//Approach-1 start from col-1 then check row wise if safe then put 'Q' and jump to next col       
 //if ind forword to last col means we get our ans

//Time complexity n! *n
//Space complexity n*2

// class Solution {
    
    
    
//     bool isSafe(int row, int col,vector<string>& chess){
//         int n = chess.size();
//         int i;
//         int j = col;
//         while(j>=0){            
//             if(chess[row][j--]=='Q')return false;        
//         }
//         i = row;
//         j = col;
//         while(i>=0 && j>=0){
            
//             if(chess[i][j] == 'Q')return false;
//             i--,j--;
//         }
//         i = row;
//         j = col;
//         while(i<n && j>=0){
            
//             if(chess[i][j] == 'Q')return false;
//             i++,j--;
//         }
//         return true;
//     }
    
//     void solve( int col, int n,vector<string>& chess, vector<vector<string>>& ans ){
        
//         if(col==n){
//             ans.push_back(chess);
//             return ;
//         }
        
//         for(int row = 0;row<n;row++ ){
//            if(isSafe(row,col,chess)){
//                chess[row][col] = 'Q';
//                solve(col+1,n,chess,ans);
//                chess[row][col] = '.';
//            }
//         }
//     }
    
// public:
//     vector<vector<string>> solveNQueens(int n) {
        
     
//     vector<vector<string>> ans;
     
//     vector<string> chess(n);
//         string st(n,'.');
//         for(int i=0;i<n;i++)
//             chess[i] = st;
    
//     solve(0,n,chess,ans);
//     return ans;
//     }
// };



/****************************************************************************/
/*************************************************************************/

//Approach-2 optimised space 
//Time complexity n! *n
//Space complexity n;


class Solution {
    
    
    
   
    void solve( int col, int n,vector<string>& chess, vector<vector<string>>& ans,
               vector<int>& vis_row,vector<int>& upper_diog,vector<int>& lower_diog){
        
        if(col==n){
            ans.push_back(chess);
            return ;
        }
        
        for(int row = 0;row<n;row++ ){
           if(vis_row[row]== 0 && upper_diog[n-1+col-row]==0 && lower_diog[row+col]==0){
               chess[row][col] = 'Q';
               vis_row[row]    =  1;
               upper_diog[n-1+col-row] = 1;
               lower_diog[row+col]  =    1;
               
               
               
               solve(col+1,n,chess,ans,vis_row,upper_diog,lower_diog);
               
               chess[row][col] = '.';              
               vis_row[row]    =  0;
               upper_diog[n-1+col-row] = 0;
               lower_diog[row+col]  =    0;
               
           }
        }
    }
    
public:
    vector<vector<string>> solveNQueens(int n) {
        
     
    vector<vector<string>> ans;
     
    vector<string> chess(n);
        string st(n,'.');
        for(int i=0;i<n;i++)
            chess[i] = st;
        
        vector<int> vis_row(n,0);
        vector<int> upper_diog(2*n-1,0);
        vector<int> lower_diog(2*n-1,0);
        
    
    solve(0,n,chess,ans,vis_row,upper_diog,lower_diog);
    return ans;
    }
};
