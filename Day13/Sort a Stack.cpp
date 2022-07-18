#include<bits/stdc++.h>
void insertAtsortedOrder(stack<int> &st,int element){
    
    if(st.empty() || st.top()<=element){
        st.push(element);
        return ;
    }
    
    int val =  st.top();
    st.pop();
    insertAtsortedOrder(st,element);
    st.push(val);
}


void sortStack(stack<int> &stack)
{
	if(stack.empty())return ;
    
    int element = stack.top();
    stack.pop();
    sortStack(stack);
    
    insertAtsortedOrder(stack,element);
    
}