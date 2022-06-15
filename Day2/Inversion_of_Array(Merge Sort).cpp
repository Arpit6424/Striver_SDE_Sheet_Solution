#include <bits/stdc++.h> 


long long mergeArr(int st,int mid, int end,long long *arr){
    
    int n1 = mid - st + 1 ;
    int n2 = end - mid ;
    
    long long *arr1 = new long long[n1];
    long long *arr2 = new long long[n2];
    
    
    for(int i=0;i<n1;i++) arr1[i] = arr[st+i];      
    for(int j=0;j<n2;j++) arr2[j] = arr[mid+1+j];
    
     long long inverse =0;
     int i=0,j=0,k = st;
     
    while(i<n1 && j<n2){
        
        if(arr1[i]<=arr2[j]){
            arr[k++] = arr1[i++];  
           
        }
           
        else{
            inverse += n1-i;
            arr[k] = arr2[j];
            k++,j++;
        }
    }    
    
    while(i<n1) {
        arr[k] = arr1[i];
        k++,i++;
    }
    
    while(j<n2) {
        arr[k] = arr2[j];
        k++,j++;
    }
    
    delete []arr1;
    delete []arr2;
    return inverse;
    
}

long long solve(int st, int end, long long *arr){
    
    long long invers_count=0;
    
    if(st<end){
        
        int mid = (st + end)/2;

         invers_count +=solve(st,mid, arr);
         invers_count +=solve(mid+1,end,arr);
         invers_count += mergeArr(st,mid,end,arr);
     } 
    
    return invers_count;
    
}

long long getInversions(long long *arr, int n){
    // Write your code here.
    
     return solve(0,n-1,arr);

}