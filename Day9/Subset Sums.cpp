class Solution
{
    void solve(int ind, vector<int> &arr, vector<int> &all_subsetsum,int sum){
        
        if(ind==arr.size()){
            all_subsetsum.push_back(sum);
            return ;
        }
        
        //pick
        solve(ind+1, arr, all_subsetsum, sum +arr[ind]);
        solve(ind+1, arr, all_subsetsum, sum);
    }
    
    
public:
    vector<int> subsetSums(vector<int> arr, int N)
    {
        // Write Your Code here
        // sort(arr.begin(),arr.end());
        // vector<int> all_subsetsum;
        //   solve(0, arr,all_subsetsum,0);
        //   return all_subsetsum;
           
           
           
           
           
           
          //Approach 2 iterative
           
      vector<int> ans;
       ans.push_back(0);
       for(int i=0;i<N;i++){
           
           int m = ans.size();
           
           for(int j=0;j<m;j++){
               ans.push_back(arr[i]+ans[j]);
           }
       }
       return ans;
        
    }
};