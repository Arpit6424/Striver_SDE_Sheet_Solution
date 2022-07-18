class Solution {
    
    void fill(vector<vector<int>>& image, int i, int j, int c1,int c2 ){
        
        if(i<0 || i==image.size() || j<0 || j==image[0].size() || image[i][j]==c1 || image[i][j] != c2)return;
        
        image[i][j]=c1;
        fill(image,i+1,j,c1,c2);
        fill(image,i-1,j,c1,c2);
        fill(image,i,j+1,c1,c2);
        fill(image,i,j-1,c1,c2);
    }
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        
        
        if(image[sr][sc] == color)return image;
        fill(image,sr,sc,color,image[sr][sc]);       
        return image;
        
    }
};