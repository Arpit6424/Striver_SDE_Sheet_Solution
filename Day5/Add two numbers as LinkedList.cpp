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


/*******************************************/
/******************************************/

//Aprroach-1 Iterative 
//Time complexity O(max(n,m));
// Space complexity O(n) ans list


// class Solution {
// public:
//     ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        
        
//         ListNode* dummy = new ListNode();
        
//         ListNode* ans = dummy;
        
//         ListNode* temp1 = l1;
//         ListNode* temp2 = l2;
        
//         int carry =0;
//         while(temp1 != NULL || temp2 != NULL || carry != 0){
            
//             int sum = carry;
//             if(temp1 != NULL)
//                 sum += temp1->val;
//             if(temp2 != NULL)
//                 sum += temp2->val;
            
//              carry = sum/10;
//             sum = sum%10;
            
//             ans->next= new ListNode(sum);
//             ans = ans->next;
            
//             if(temp1 != NULL)
//                 temp1 = temp1->next;
            
//             if(temp2 != NULL)
//                 temp2 = temp2->next;
//         }
        
//         return dummy->next;
        
//     }
// };



/*******************************************/
/******************************************/

//Aprroach-2 recursively 
//Time complexity O( max(n,m) );
// Space complexity O(n + n ) ans list


class Solution {
    
    
    ListNode* solve(ListNode* temp1, ListNode* temp2, int carry){
        
        //if Both the list is empty 
        if(temp1 == NULL && temp2 == NULL){            
            if(carry==0)return NULL;
            else return new ListNode(carry);
        }
        
        int sum = carry;
        if(temp1 != NULL){
            sum += temp1->val;
            temp1 = temp1->next;
        }
        
         if(temp2 != NULL){
            sum += temp2->val;
            temp2 = temp2->next;
        }
        
        carry = sum/10;
        sum = sum % 10;
        
        ListNode* dummy = new ListNode(sum);
        dummy->next = solve(temp1, temp2, carry );
        return dummy;
    }
    
    
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {     

         return solve(l1,l2,0);       
 
    }
};


/*******************************************/
/******************************************/

//Aprroach-2 recursively short code  
//Time complexity O( max(n,m) );
// Space complexity O(n + n ) ans list

// class Solution {
// public:
//     ListNode* addTwoNumbers(ListNode* l1, ListNode* l2, int carry = 0) {
//         if(!l1 && !l2) {
//             if(carry) {
//                 return new ListNode(carry);
//             } else {
//                 return NULL;
//             }
//         }
//         int sum = l1 ? l1->val : 0;
//         sum += l2 ? l2->val : 0;
//         sum += carry;
//         ListNode *newNode = new ListNode(sum%10);
//         newNode->next = addTwoNumbers(l1 ? l1->next : NULL, l2 ? l2->next : NULL, sum/10);
        
//         return newNode;
//     }
// };


/*******************************************/
/******************************************/

