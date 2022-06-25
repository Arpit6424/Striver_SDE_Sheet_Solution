

int countSmallarEqualToMid(vector<int> &arr,int element){
    
    int low = 0;
    int high = arr.size()-1;
    
    while(low<=high){
        
        int mid = (low+high)/2;
        
        if(arr[mid]<=element)low = mid+1;
        else high = mid-1;
    }
    return low;
}


int Solution::findMedian(vector<vector<int> > &A) {
    int n = A.size();
    int m = A[0].size();
    int low = 1;
    int high = 1e9;
    
    while(low<=high){
        
        int mid = (low+high)/2;
        
        int cnt =0;
        for(int i=0;i<A.size();i++){
            cnt += countSmallarEqualToMid(A[i],mid);
        }
        
        
        if(cnt<=(n*m)/2)low = mid+1;
        else high = mid-1;
    }
    
    return low;
    
}
