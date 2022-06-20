// int findMinimumCoins(int amount) 
// {
//     // Write your code here
    
//     vector<int> currency{1,2,5,10,20,50,100,500,1000};
//     int n  =9;
//     int count =0 ;
    
//     while(amount){
        
//         for(int i=n-1;i>=0;i--){
//             if(amount>=currency[i]){
//                 amount -= currency[i];
//                 count++;
//                 break;
//             }
//         }
//     }
//     return  count;
// }



int findMinimumCoins(int amount) 
{
    // Write your code here
    
    vector<int> currency{1,2,5,10,20,50,100,500,1000};
    int n  =9;
    int count =0 ;
    
    
        
        for(int i=n-1;i>=0;i--){
            if(amount/currency[i]>=1){
                count += amount/currency[i];
                amount = amount% currency[i];
            }
            if(amount==0)break;
        }
    
    return  count;
}