class Solution{
    public:
    //Function to find the minimum number of platforms required at the
    //railway station such that no train waits.
    int findPlatform(int arr[], int dep[], int n)
    {
    	// Your code here
    	sort(arr, arr+n);
    	sort(dep,dep+n);
    	
    	int max_platform = 1;
    	int cur_platform = 1;
    	
    	int i=1;
    	int j =0;
    	while(i<n && j<n){
    	    
    	    if(arr[i]<=dep[j]){
    	        cur_platform++;
    	        i++;
    	    }
    	    else{
    	        cur_platform--;
    	        j++;
    	    }
    	    
    	    if(cur_platform > max_platform)
    	    max_platform = cur_platform;
    	}
    	return max_platform;
    }
};