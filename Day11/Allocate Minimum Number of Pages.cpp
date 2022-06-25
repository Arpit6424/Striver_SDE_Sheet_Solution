
 bool allocationPossible(vector<int> &A, int n1, int B,int max_page){
     
     int student =0;
     int pages = 0;
     
     for(int i=0;i<n1;i++){
         
        
         
         if(pages + A[i] > max_page){
             student++;
             pages = A[i];
             if(pages>max_page)return false;
             
         }
         else
         pages += A[i];
     }
     
     if(student<B)return true;
     return false;
 }
int Solution::books(vector<int> &A, int B) {
    int n1 = A.size();
    
    if(B>n1)return -1;
    int high = 0;
    int low = A[0];
    
    for(int i=0;i<n1;i++){
        high += A[i];
        if(low >A[i]) low = A[i];
    }
    
    
    while(low<=high){
        int mid = (low+high)>>1;
        if(allocationPossible(A,n1,B,mid)){
            
            high = mid-1;
        }
        else
        low = mid+1;
    }
    return low;
}


 
