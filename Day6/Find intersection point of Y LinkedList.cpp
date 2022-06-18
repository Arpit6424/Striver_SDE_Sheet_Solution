/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

/********************************************************/
/*******************************************************/

//Approach -1 Using hashMap
//Time Complexity (n + m)
//Space complexity O(n);


// class Solution {
// public:
//     ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        
//         unordered_set<ListNode*> st;
//         ListNode *temp = headA;
//         while(temp != NULL){
            
//             st.insert(temp);
//             temp = temp->next;
//         }
        
//         temp = headB;
//         while(temp != NULL){
            
//             if(st.find(temp) != st.end())return temp;
//             temp = temp->next;
//         }
        
//         return NULL;
        
//     }
// };


/********************************************************/
/*******************************************************/

//Approach -2 Using length of list
//Time Complexity (n + m) + (n);
//Space complexity O(1);


// class Solution {
// public:
//     ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        
//         int len1 =0;
//         int len2 = 0;
        
//       ListNode *temp =headA ;
//         while(temp != NULL){
//             len1++;
//             temp = temp->next;
//         }
//         temp = headB ;
//           while(temp != NULL){
//             len2++;
//             temp = temp->next;
//         }
        
//         if(len1>len2){
//             int x = len1 - len2;
//             while(x--)
//                 headA = headA->next;
               
            
//         }
//         else if( len1<len2){
//              int x = len2 - len1;
//             while(x--)
//                 headB = headB->next;
                
            
            
//         }
        
        
//         while(headA != NULL && headB != NULL){
            
//             if(headA == headB)return headA;
//             headA = headA->next;
//             headB = headB->next;
            
//         }
        
//         return NULL;
        
//     }
// };



/********************************************************/
/*******************************************************/

//Approach -3
//Time Complexity (n + m) + (n);
//Space complexity O(1);



class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        
          ListNode* a = headA;
          ListNode* b = headB;
        
        while(a != b){
            
            a = a==NULL?headB : a->next;
            b = b==NULL?headA : b->next;
        }
        return a;
        
    }
};

















