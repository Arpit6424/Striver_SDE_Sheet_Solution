//Approach-1
// Time Complexity O(1) for each operation
// Space Complexity O(2n)


// class MinStack {
// public:
    
//     stack<int> input;
//     stack<int> min;  //we can use pair<int, int> only one stack
//     MinStack() {
        

//     }
    
//     void push(int val) {
//         input.push(val);
        
//         if(min.empty() || min.top()>val)min.push(val);
//         else min.push(min.top());
            
        
//     }
    
//     void pop() {
        
//         if(!input.empty()){
//             input.pop();
//             min.pop();
//         }
        
//     }
    
//     int top() {
        
//       if(input.empty())return -1;
//         return input.top();
        
//     }
    
//     int getMin() {
        
//         if(!min.empty())return min.top();
//         return INT_MAX;
//     }
// };



//Approach-2
// Time Complexity O(1) for each operation
// Space Complexity O(n)




class MinStack {
public:
    
    stack<long long> st;
    long long mini;
    
    MinStack() {
        mini = INT_MIN;

    }
    
    void push(int val) {
        long long value = val;
        if(st.empty()){
            mini = value;
            st.push(value);
        }
        else{
            if(value < mini){
                st.push(2*value -mini);
                mini = value;
            }
            else{
                st.push(value);
            }
        }
   
    }
    
    void pop() {
        if(st.empty())return;
        
        long long element = st.top();
        st.pop();
        
        if(element < mini){
            mini = 2*mini - element;
        }
    }
    
    int top() {
        if(st.empty())return -1;
        
        long long element = st.top();
        if(element < mini)return mini;
        return element;
    }
    
    int getMin() {
        return mini;
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */


















/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */