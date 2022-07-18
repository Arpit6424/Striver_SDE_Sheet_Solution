#include<bits/stdc++.h>
class Queue {
     
    stack<int> st1;
    stack<int> st2;
    
    public:
    Queue() {
        // Initialize your data structure here.
    }

    void enQueue(int val) {
        
        while(!st2.empty()){
            st1.push(st2.top());
            st2.pop();
        }
         st1.push(val);
        
        while(!st1.empty()){
            st2.push(st1.top());
            st1.pop();
        }
        
    }

    int deQueue() {        
      if(st2.empty())return -1;
        
      int element = st2.top();
      st2.pop();
      return element;
    }

    int peek() {
       if(st2.empty()) return -1;
        return st2.top();
    }

    bool isEmpty() {
        return st2.empty();
    }
};