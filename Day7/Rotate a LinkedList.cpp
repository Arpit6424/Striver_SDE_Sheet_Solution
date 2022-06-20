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
/******************************************************************/
/********************************************************************/

//Approach-1 rotate one by one till k times 
//Time complexity o(k*n) + n;
//space complexity O(1);

// class Solution {
    
//  ListNode* oneRotation(ListNode* head){
     
//      ListNode* prev = NULL;
//      ListNode* cur = head;
     
//      while(cur->next != NULL){
         
//          prev = cur;
//          cur = cur->next;
//      }
     
//      cur->next = head;
//      prev->next = NULL;
//      return cur;
//  }   
    
// public:
//     ListNode* rotateRight(ListNode* head, int k) {
        
             
//         if(head==NULL || head->next == NULL)return head;
        
//         ListNode* temp = head;
//         int len =0;
//         while(temp){
//             len++;
//             temp = temp->next;
//         }
        
//         temp = head;
//         k = k%len;
        
//         while(k){
//             head = oneRotation(head);
//             k--;
//         }
        
//         return head;
        
//     }
// };






/******************************************************************/
/********************************************************************/

//Approach-2 make circular list then cut index according to k 
//Time complexity o(n + n -k );
//space complexity O(1);






class Solution {  
    
public:
    ListNode* rotateRight(ListNode* head, int k) {
        
        if(head==NULL || head->next == NULL)return head;
        
        ListNode* cur = head;
        int len =1;
        while(cur->next){
            len++;
            cur = cur->next;
        }
        
        cur->next = head;
        
        
        k = k%len;
        k = len - k;
        
        cur = head;
        while(k>1){
            cur = cur->next;
            k--;
        }
        
        head = cur->next;
        cur->next = NULL;
        return head;
        
    }
};



















