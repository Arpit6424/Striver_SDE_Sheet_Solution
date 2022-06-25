
long double multipy(long double mid , int n){
    
    long double ans=1.0;
    for(int i=1;i<=n;i++){
        ans *= mid;
    }
    return ans;
}
double findNthRootOfM(int n, long long m) {
	// Write your code here.
    
   long  double low = 1.0;
    long double high = m;
    long double eps = 1e-9;
    
    while((high-low)>eps){        
       long double  mid = (low+high)/2.0;
        if(multipy(mid,n)>m)
            high = mid;
        
        else
            low = mid;
    }
    
    return low;
}
