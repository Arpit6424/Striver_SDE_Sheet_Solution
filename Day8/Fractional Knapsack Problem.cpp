//Approach-1 make vector for copy the input
//Time complexit O(nlogn + n )
//Space complexit O(n);

// class Solution
// {
//   static bool sortbysecd(const pair<int, int> &a,const pair<int, int> &b){
//       return ((double)a.first/a.second) > ((double)b.first/b.second);
//   }
   
    
//     public:
//     //Function to get the maximum total value in the knapsack.
//     double fractionalKnapsack(int W, Item arr[], int n)
//     {
//         // Your code here
        
//         vector<pair<int, int>> data(n);
        
//         for(int i=0;i<n;i++){
//             data[i] = make_pair(arr[i].value,arr[i].weight);
//         }
        
//         sort(data.begin(),data.end(),sortbysecd);
//         double profit =0;
        
//         for(int i=0;i<n;i++){
            
//             if(W>0){
                
//                 if(W>=data[i].second){
//                     profit +=(double) data[i].first;
//                     W = W-data[i].second;
//                 }
//                 else{
//                     profit += (double)(W*((double)data[i].first/data[i].second)) ;
//                     W = 0;
                   
                    
//                 }
//             }
           
//         }
//          return profit;
//     }
        
// };







//Approach-2 
//Time complexit O(nlogn + n )
//Space complexit O(1);



class Solution
{
   static bool sortbysecd(Item a, Item b){
       return ((double)a.value/a.weight) > ((double)b.value/b.weight);
   }
   
    
    public:
    //Function to get the maximum total value in the knapsack.
    double fractionalKnapsack(int W, Item arr[], int n)
    {
        // Your code here
        
       sort(arr,arr+n , sortbysecd);
    
        double profit =0;
        
        for(int i=0;i<n;i++){
            
            if(W>0){
                
                if(W>=arr[i].weight){
                    profit +=(double) arr[i].value;
                    W = W-arr[i].weight;
                }
                else{
                    profit += (double)(W*((double)arr[i].value/arr[i].weight)) ;
                    W = 0;
                    break;
                   
                    
                }
            }
           
        }
         return profit;
    }
        
};
