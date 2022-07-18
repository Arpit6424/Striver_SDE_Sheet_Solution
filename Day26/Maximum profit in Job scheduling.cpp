class Solution 
{
    public:
    //Function to find the maximum profit and the number of jobs done.
    vector<int> JobScheduling(Job arr[], int n) 
    { 
        // your code here
        vector<pair<int, int>> job(n);
        
        int maxdead = -1;
        for(int i=0;i<n;i++){
            job[i].first = arr[i].profit;
            job[i].second = arr[i].dead;
            
            if(arr[i].dead>maxdead) maxdead = arr[i].dead;
        }
        
        sort(job.begin(),job.end());
        
        vector<int> maxPro_job(maxdead+1,-1);
        
        int count =0, totProfit =0;

        for(int i=n-1;i>=0;i--){
            
            int maxDead = job[i].second;
            int profit = job[i].first;
         
            for(int j=maxDead;j>=1;j--){
                if(maxPro_job[j]==-1){
                    maxPro_job[j] = profit;
                    
                    totProfit += profit;
                    count++;
                    break;
                    
                }
            }
            
        }
        
      
        
        return {count,totProfit};
        
    } 
};