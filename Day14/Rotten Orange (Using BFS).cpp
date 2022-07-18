// class Solution {
// public:
//     int orangesRotting(vector<vector<int>>& grid) {
//         int n = grid.size();
//         int m = grid[0].size();
        
//         queue< pair<int,int>> q;
        
//         int freshcnt = 0;
//         for(int i=0;i<n;i++){
//             for(int j=0;j<m;j++){
//                 if(grid[i][j]==2)q.push({i,j});
//                 if(grid[i][j]==1)freshcnt++;
//             }
//         }
    
//        if(q.empty() && freshcnt ==0)return 0;
        
        
//         int cnt = 0;
        
//         while(!q.empty()){
            
 
//             cnt++;
//             int k = q.size();
//             while(k--){
                
//                 pair<int,int> temp = q.front();
//                 q.pop();
//                 int i = temp.first;
//                 int j = temp.second;

//                 //left
//                 if(j-1>=0 && grid[i][j-1] == 1){
//                     freshcnt--;
//                     grid[i][j-1] = 2;
//                     q.push({i,j-1});
//                 }
//                 //right
//                 if(j+1 < m  && grid[i][j+1] == 1 ){
//                     freshcnt--;
//                     grid[i][j+1] = 2;
//                     q.push({i,j+1});
//                 }

//         //             //down
//                 if(i+1 < n && grid[i+1][j] == 1 ){
//                     freshcnt--;
//                     grid[i+1][j] = 2;
//                     q.push({i+1,j});
//                 }

//         //             // up
//                 if(i-1 >=0 && grid[i-1][j] == 1){
//                     freshcnt--;
//                     grid[i-1][j] = 2;
//                     q.push({i-1,j});
//                 }

//             }
                
            
//         }
        
   
//         if(freshcnt)return -1;
//         return cnt-1;
//     }
// };















class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        
        queue< pair<int,int>> q;
        
        int freshcnt = 0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==2)q.push({i,j});
                if(grid[i][j]==1)freshcnt++;
            }
        }
    
       if( freshcnt ==0)return 0;
        
        
        int cnt = 0;
        int di[] ={0,0,+1,-1};
        int dj[] ={-1,1,0,0};
        
        while(!q.empty()){
          cnt++;
          int k = q.size();
         
            while(k--){
                
                int x = q.front().first;
                int y= q.front().second;
                q.pop();
                
                for(int i=0;i<4;i++){
                    int nextx = x + di[i];
                    int nexty = y + dj[i];
                    
                    if(nextx<0 || nextx==n || nexty<0 || nexty==m || grid[nextx][nexty] != 1)continue;
                    grid[nextx][nexty] = 2;
                    q.push({nextx,nexty});
                    freshcnt--;                   
                    
                }
            }
            
            
        }
   
        if(freshcnt)return -1;
        return cnt-1;
    }
};