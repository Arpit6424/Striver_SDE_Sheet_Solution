
// Approach-1 find rightsmallerheightelement and lefttsmallerheightelement the find width from these array and find area
//Time complexity O(5n) beacase for rightsmaller O(n)+(n) and for left smaller again O(n)+ O(n) and finaly for finding area of each element O(n);
//Spcae complexity(3n) // right ,left ,stack

// class Solution {
    
    
//     void rightSmallerElementindex(vector<int>& heights,vector<int> &right,int n){        
        
//         stack<int> st;
        
//         for(int i=n-1;i>=0;i--){
            
//             while(!st.empty() && heights[st.top()] >= heights[i]){
//                 st.pop();
//             }
            
//             if(st.empty())right[i] = n;
//             else right[i] = st.top();
//             st.push(i);
//         }         
//     }
    
//     void leftSmallerElementindex(vector<int>& heights,vector<int> &left,int n){
        
//         stack<int> st;
        
//         for(int i=0;i<n;i++){
            
//             while(!st.empty() && heights[st.top()] >= heights[i]){
//                 st.pop();
//             }
//             if(st.empty())left[i] = -1;
//             else left[i] = st.top();
//             st.push(i);
//         }
//     }
// public:
//     int largestRectangleArea(vector<int>& heights) {
        
//         int n= heights.size();
//         vector<int> right(n);
//         vector<int> left(n);
        
        
//         rightSmallerElementindex(heights,right,n);
       
//         leftSmallerElementindex(heights,left,n);
      
        
//         int maxArea = 0;
        
//         for(int i=0;i<n;i++){
            
//             int area = (right[i]-left[i] -1) * heights[i];
//             maxArea = max(maxArea,area);
//         }
//         return maxArea;
        
        
//     }
// };




//Optimised approach
// Time complexity O(2n);
// Space complexity O(n);

class Solution {
    
    
    
public:
    int largestRectangleArea(vector<int>& heights) {
        
        int n= heights.size();
        
        stack<int> st;
        int maxArea =0;
        
        for(int i=0;i<=n;i++){
            
            while(!st.empty() &&(i==n || heights[st.top()] >= heights[i]) ){
                int height = heights[st.top()];
                st.pop();
                
                int width;
                if(st.empty())width = i;
                else width = i - st.top()-1;
  
                int area = height*width;
                maxArea = max(maxArea,area);
                
            }
            st.push(i);
        }
        return maxArea;
        
        
    }
};
























