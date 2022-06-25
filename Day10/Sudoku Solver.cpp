class Solution {
    
    bool isSafe(int row, int col,char digit, vector<vector<char>>& board){
        
        for(int i=0;i<9;i++){
            if(board[i][col]==digit)return false;
            if(board[row][i]==digit)return false;
            if(board[3*(row/3)+i/3][3*(col/3)+i%3]==digit)return false;            
        }
        return true;
        
        
    }
    
     bool solve(vector<vector<char>>& board ){
         
         
         for(int i=0;i<9;i++){
             for(int j=0;j<9;j++){
                 
                 if(board[i][j]=='.'){
                     for(char digit = '1';digit<='9';digit++){
                         
                         if(isSafe(i,j,digit,board)){
                             
                             board[i][j]= digit;
                             if(solve(board))return true;
                             board[i][j] = '.';
                         }
                     }
                     return false;
                     
                 }
                 

             }
         }
         return true;
     }
    
public:
    void solveSudoku(vector<vector<char>>& board) {
        
        solve(board);
        
    }
};