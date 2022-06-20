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

public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        if(!head or !head->next or k==1) return head;
        
        ListNode* temp = head;
        int len =0;
        while(temp != NULL){
            len++;
            temp = temp->next;
        }
        
        if(len<k)return head;
        

            
        ListNode* prev  = NULL;
        ListNode* cur   = head;
        ListNode* next  = NULL;
            
        int x = k;            
        while(x && cur){

            next = cur->next;
            cur->next = prev;
            prev = cur;
            cur = next;
            x--;
        }
            
    
       head->next = reverseKGroup(next , k);
            
        
        
        
        return prev;
        
    }
};