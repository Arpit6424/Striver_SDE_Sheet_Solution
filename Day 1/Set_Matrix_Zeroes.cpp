class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        
        int totRows = matrix.size();
        int totCols = matrix[0].size();
        
//         vector<int> dummyR(totCols,1);//Make dummy Row
//         vector<int> dummyC(totRows,1);//Make dummy Col
        
        
//         for(int row=0;row<totRows;row++){
            
//             for(int col=0;col<totCols;col++){
                
              
//                 if(matrix[row][col]==0){
                    
//                     dummyR[col] = 0;
//                     dummyC[row] = 0;
//                 }
//             }
//         }
        

//             for(int row=0;row<totRows;row++){

//                for(int col=0;col<totCols;col++){

//                 if( dummyR[col]==0 || dummyC[row]==0)matrix[row][col]=0;
               
//             }
//         }
    
       int colZero = 1;
        for(int row=0;row<totRows;row++){
            if(matrix[row][0]==0)colZero=0;

            for(int col=1;col<totCols;col++){


                if(matrix[row][col]==0){
                    matrix[0][col] = 0;
                    matrix[row][0] = 0; 

                }
            }
        }
        
        
        

       for(int row=totRows-1;row>=0;row--){

            for(int col=totCols-1;col>=1;col--)
                
                if(matrix[0][col]==0 || matrix[row][0]==0)
                     matrix[row][col] = 0;
 
              if(colZero==0)matrix[row][0]= 0;
        } 
        
        
        
        
        
        
        

        
        
    }
};