/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        Node* temp = head;
        if(head== NULL)return head;
        
     //Step1   
    while(temp != NULL){        
        Node* newNode = new Node(temp->val);
        newNode->next = temp->next;
        temp->next = newNode;
        temp = newNode->next;
    }
        
    temp = head;
     //Step 2 Assign Random pointer   
    while(temp){        
        if(temp->random != NULL)
          temp->next->random = temp->random->next;
        
         temp = temp->next->next;        
    }
        
     Node* dummy = new Node(0);
    dummy->next = head->next;
    Node* temp1 = head;
    Node* temp2 = head->next;
     while(temp1 != NULL){
         
         temp1->next = temp2->next;
         if(temp2->next != NULL)
         temp2->next = temp2->next->next;
       
             
         temp1 = temp1->next;
         temp2 = temp2->next;
         
     }
        
        return dummy->next;
        
        
    }
};