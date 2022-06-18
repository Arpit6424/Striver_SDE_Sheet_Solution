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


/*********************************************/
/********************************************/

//Approach-1 Iterative 
//Time complexity O(len1 + len2)
//space complexity O(1);


class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        
        if(!list1)return list2;
        if(!list2)return list1;
        
        // if(list1->val > list2->val ) return mergeTwoLists(list2,list1);
        
        ListNode* dummy = new ListNode();
        ListNode* ans = dummy;
        
        ListNode* temp1 = list1;
        ListNode* temp2 = list2;
        // ListNode* ans = list1;
        
        
        while(temp1 != NULL && temp2 != NULL){
            
            
            if(temp1->val<=temp2->val){
                
                ans->next = temp1;
                ans = ans->next;
                temp1 = temp1->next;
                
            }
            else{
                
                ans->next = temp2;
                ans = ans->next;
                temp2 = temp2->next;
            }
        }
        
        
        if(temp1 != NULL)
            ans->next = temp1;
        if(temp2 != NULL)
            ans->next = temp2;
        
        return dummy->next;
        
    }
};

/*********************************************/
/********************************************/

//Approach-2 Recursively 
//Time complexity O(len1 + len2)
//space complexity O(len1 + len2);


// class Solution {
// public:
//     ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        
//         if(!list1)return list2;
//         if(!list2)return list1;
        
//         if(list1->val > list2->val ) return mergeTwoLists(list2,list1);
        
//         ListNode* ans = list1;
        
//         ans->next = mergeTwoLists(list1->next , list2);
//         return ans;
        
//     }
// };


/*********************************************/
/********************************************/