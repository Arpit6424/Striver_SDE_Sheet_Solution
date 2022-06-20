class Solution
{
   static bool sortbysec(const pair<int,int> &a, const pair<int,int> &b){
         return (a.second < b.second);
        
    }

    public:
    //Function to find the maximum number of meetings that can
    //be performed in a meeting room.
    int maxMeetings(int start[], int end[], int n)
    {
        // Your code here
        vector<pair<int,int>> time(n);
        
        for(int i=0;i<n;i++){
            time[i] = make_pair(start[i],end[i]);
        }
        
        
        sort(time.begin(),time.end(),sortbysec);
        
        int count_meeting =0;
        int prevEnd =-1;
        
         for(auto it : time){
            
            if(it.first > prevEnd){
                count_meeting++;
                prevEnd = it.second;
                }
                
                
            }
            return count_meeting;
            
        }
    
};