/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
/****************************************************/
/***************************************************/

// Approach-1 Using Hashmap store node if we found again then loop is present
//Time complexity O(n);
// Space Complexity O(n);

// class Solution {
// public:
//     bool hasCycle(ListNode *head) {
        
//         unordered_set<ListNode*> st;
//         ListNode* temp = head;
//         while(head != NULL){
            
//             if(st.find(head) != st.end())return true;
//             st.insert(head);
            
//             head  = head->next;
//         }
//         return false;
        
//     }
// };


/****************************************************/
/***************************************************/

// Approach-2  slow pointer , fast pointer
//Time complexity O(n);
// Space Complexity O(1);


class Solution {
public:
    bool hasCycle(ListNode *head) {
        
         if(head==NULL)return false;
        ListNode* fast = head;
        ListNode* slow = head;
        
        
       while( fast->next != NULL && fast->next->next != NULL  ){
           
           slow = slow->next;
           fast = fast->next->next;
          
           if(fast == slow)return true;
               
         }
        return false;
    }
};