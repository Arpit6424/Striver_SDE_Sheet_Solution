class Solution {
public:
    string getPermutation(int n, int k) {
        
        int fact = 1;
        vector<int> numbers(n);
        
        for(int i=1;i<n;i++){
            
            fact =  fact * i;
            numbers[i-1] = i ;
        }
        numbers[n-1] = n;
        
        string ans = "";
        k = k-1;
        
        
        while(true){
            if(fact==0)return ans;
            ans = ans + to_string(numbers[k/fact]);
            numbers.erase(numbers.begin() + k/fact);
            if(numbers.size()==0){
                break;
            }
            cout<<fact<<" ";
            k = k % fact;
            fact = fact /numbers.size();
        }
        return ans;
        
        

        
        
        
    }
};