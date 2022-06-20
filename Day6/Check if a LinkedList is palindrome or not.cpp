/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
    
    ListNode* reverseList(ListNode* head) {

    if(head==NULL || head->next==NULL)
        return head;


    ListNode* newhead = reverseList(head->next);

    head->next->next = head;
    head->next = NULL;

    return newhead;
    }
    
    
public:
    bool isPalindrome(ListNode* head) {
        
        if(head->next == NULL)return true;
        
        ListNode* temp = head;
        int len =0;
        
        while(temp != NULL){            
            temp = temp->next;
            len++;
        }
        
     
        cout<<len;
        
        len = (len-1)/2;
        
        ListNode* temp1 = head;
        ListNode* temp2 = head;
        
        while(len>0){
             temp2 = temp2->next; 
            len--;
        }          
            
        temp2->next = reverseList(temp2->next);
        
        while(temp2->next != NULL){
            
            if(temp1->val != temp2->next->val)return false;
            temp1 = temp1->next;
            temp2 = temp2->next;
        }

              
        return true;
        
    }
};