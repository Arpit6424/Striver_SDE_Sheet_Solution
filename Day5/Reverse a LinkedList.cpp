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




/********************************/
/*******************************/
//Approach-1 Iterative
//Time complexity O(n);
//Space complexity O(1);





// class Solution {
// public:
//     ListNode* reverseList(ListNode* head) {
        
//         ListNode* prev  = NULL;
//         ListNode* cur   = head;
//         ListNode* next  = NULL;
        
//         while(cur != NULL){
            
//             next = cur->next;
//             cur->next = prev;
//             prev = cur;
//             cur = next;
//         }
        
//         return prev;
        
//     }
// };


/********************************/
/*******************************/
//Approach-1  recursively
//Time complexity O(n);
//Space complexity O(n);

class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        
        if(head==NULL || head->next==NULL)
            return head;
        
        
        ListNode* newhead = reverseList(head->next);
        
        head->next->next = head;
        head->next = NULL;
        
        return newhead;
        
    }
};