#include<bits/stdc++.h>
// vector<int> mergeKSortedArrays(vector<vector<int>>&kArrays, int k)
// {
//     // Write your code here. 
//     vector<int> ans;
//     for(auto it: kArrays){
//         for(int i : it)
//             ans.push_back(i);
//     }
//     sort(ans.begin(),ans.end());
//     return ans;
// }


class node{
      public:
    int data;
    int ind;
    int arrayNo;
  
    node(int data,int ind, int arrayNo){
        this->data = data;
        this->ind = ind;
        this->arrayNo = arrayNo;
    }
};

class compare{
    public:
    bool operator()(node* a, node* b){
        return a->data > b->data;
    }
};

vector<int> mergeKSortedArrays(vector<vector<int>>&kArrays, int k)
{
  priority_queue<node*, vector<node*>,compare> minheap;
    
    for(int i=0;i<k;i++){
       node* temp = new node(kArrays[i][0],0,i);
        minheap.push(temp);
    }
    vector<int> ans;
    while(minheap.size() > 0) {
        
        node* temp = minheap.top();
        minheap.pop();
        
        int data = temp->data;
        int ind = temp->ind;
        int arrayNo = temp->arrayNo;
        
        ans.push_back(data);
        
        if(ind +1 < kArrays[arrayNo].size()){
            node* next = new node(kArrays[arrayNo][ind+1],ind+1,arrayNo);
              minheap.push(next);
        }
         

    }
    return ans;

    
}