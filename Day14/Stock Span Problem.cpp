class StockSpanner {
public:
    
    stack<pair<int,int>> st;
    int ind =0;
    
    StockSpanner() {
        
    }
    
    int next(int price) {
        ind++;
        
        while(!st.empty() && st.top().first <= price)
            st.pop();
        
        
        if(st.empty()){
            st.push({price,ind});
                return ind;
        }
        else{
            
            int prevGreaterind = st.top().second;
            st.push({price,ind});
            return ind-prevGreaterind;
        }
        
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */