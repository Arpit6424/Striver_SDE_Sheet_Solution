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


/***************************************************/
/**************************************************/

//Approach-1 find len then traverse len/2
//time comlexity O(2n);
//space O(1)


// class Solution {
// public:
//     ListNode* middleNode(ListNode* head) {
        
//        int len =0;
        
//         ListNode* temp = head;
        
//         while(temp){
            
//             temp = temp->next;
//             len++;
//         }
        
//         len = len/2;
        
//         ListNode* newhead = head;
//         while(len){
//             newhead = newhead->next;
//             len--;
//         }
//         return newhead;
        
//     }
// };

/***************************************************/
/**************************************************/
//Approach-2 optimize aprroach-1; two pointer 
//time comlexity O(n);
//space O(1)

class Solution {
public:
    ListNode* middleNode(ListNode* head) {
        
      ListNode* slow = head;
      ListNode* fast = head;
       
      while(fast && fast->next){
          
          slow = slow->next;
          fast = fast->next->next;
      }
        return slow;
        
    }
};



/***************************************************/
/**************************************************/