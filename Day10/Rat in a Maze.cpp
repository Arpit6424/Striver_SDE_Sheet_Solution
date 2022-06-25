// class Solution{
    
    
//     void solve(int row,int col , string path ,vector<string> &allpath,vector<vector<int>> &m, int n,
//     vector<vector<int>>& vis){
        
//         if(row == n-1 && col == n-1){
//             allpath.push_back(path);
//             return ;
//         }
        
        
//         //Down
//         if(row+1<n && vis[row+1][col] == 0 && m[row+1][col] == 1){
//             vis[row][col] = 1;
//             solve(row+1,col,path+'D',allpath,m,n,vis);
//             vis[row][col] = 0;
//         }
        
//       //left
//       if(col-1>=0 && vis[row][col-1] == 0  && m[row][col-1] == 1){
//           vis[row][col] = 1;
//           solve(row, col-1,path+'L',allpath,m,n,vis);
//           vis[row][col] = 0;
//       }
       
//       //Right
//       if(col+1<n && vis[row][col+1] == 0 && m[row][col+1] == 1){
//           vis[row][col] = 1;
//           solve(row, col+1, path+'R',allpath,m,n,vis);
//           vis[row][col] = 0;
//       }
       
//       //up
//       if(row-1>=0 && vis[row-1][col] == 0 && m[row-1][col] == 1){
//           vis[row][col] = 1;
//           solve(row-1, col, path+'U',allpath,m,n,vis);
//           vis[row][col] = 0;
           
//       }
           
        
//     }
    
    
//     public:
//     vector<string> findPath(vector<vector<int>> &m, int n) {
//         // Your code goes here
        
        
//         vector<string> allpath;
//         string path ="";
//         vector<vector<int>> vis(n,vector<int>(n,0));
//         if(m[0][0]==1)
//          solve(0,0,path,allpath,m,n,vis);
//         return allpath;
        
        
//     }
// };




/******************************************************************/
/*******************************************************************/





class Solution{
    
    
    void solve(int row,int col , string path ,vector<string> &allpath,int di[],int dj[],vector<vector<int>> &m, int n,
    vector<vector<int>>& vis){
        
        if(row == n-1 && col == n-1){
            allpath.push_back(path);
            return ;
        }
   
        string st ="DLRU";
        for(int ind=0;ind<4;ind++){
            
            int nexti = row + di[ind];
            int nextj = col + dj[ind];
            
            if(nexti>=0 && nexti<n && nextj>=0 && nextj<n && vis[nexti][nextj] ==0 && m[nexti][nextj]==1){
                
                vis[row][col] = 1;
                solve(nexti,nextj,path + st[ind],allpath,di,dj,m,n,vis);
                 vis[row][col] = 0;
                
            }
        }
        
    }
    
    
    public:
    vector<string> findPath(vector<vector<int>> &m, int n) {
        // Your code goes here
        
        
        vector<string> allpath;
        string path ="";
        vector<vector<int>> vis(n,vector<int>(n,0));
        int di[]={1,0,0,-1};
        int dj[]={0,-1,+1,0};
        if(m[0][0]==1)
         solve(0,0,path,allpath,di,dj,m,n,vis);
        return allpath;
        
        
    }
};



