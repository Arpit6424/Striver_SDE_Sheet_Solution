/* Node structure  used in the program

struct Node{
	int data;
	struct Node * next;
	struct Node * bottom;
	
	Node(int x){
	    data = x;
	    next = NULL;
	    bottom = NULL;
	}
	
};
*/

/*  Function which returns the  root of 
    the flattened linked list. */
    
    
    
    //Approach-2 recursely;
    
 
//  Node* solve(Node* head1, Node* head2){
     
//      if(head1==NULL)return head2;
//      if(head2==NULL)return head1;
     
  
     
//      Node *dummy = new Node(0);
//      Node* ans = dummy;
   
     
//     while(head1 != NULL && head2 != NULL){
    
    
//     if(head1->data<=head2->data){
        
//         ans->bottom = head1;
//         ans = ans->bottom;
//         head1 = head1->bottom;
        
//     }
//     else{
        
//         ans->bottom = head2;
//         ans = ans->bottom;
//         head2 = head2->bottom;
//     }
// }
        
//     if(head1 != NULL)
//         ans->bottom = head1;
        
//     if(head2 != NULL)
//       ans->bottom = head2;
      
        
//          return dummy->bottom;
//  }
    
    
// Node *flatten(Node *root)
// {
//      if(root == NULL || root->next==NULL)
//       return root;
//   // Your code here
//     root->next = flatten(root->next);
//   return solve(root , root->next);
// }

/******************************************************/
/******************************************************/





//Approach-2 Iterative


 Node* solve(Node* head1, Node* head2){
     
     if(head1==NULL)return head2;
     if(head2==NULL)return head1;
     
  
     
     Node *dummy = new Node(0);
     Node* ans = dummy;
   
     
    while(head1 != NULL && head2 != NULL){
    
    
    if(head1->data<=head2->data){
        
        ans->bottom = head1;
        ans = ans->bottom;
        head1 = head1->bottom;
        
    }
    else{
        
        ans->bottom = head2;
        ans = ans->bottom;
        head2 = head2->bottom;
    }
}
        
    if(head1 != NULL)
        ans->bottom = head1;
        
    if(head2 != NULL)
      ans->bottom = head2;
      
        
         return dummy->bottom;
 }
Node *flatten(Node *root)
{
     if(root == NULL || root->next==NULL)
       return root;
   // Your code here
   
   Node* list1 = root;
   Node* list2 = root->next;
   
   while(list2){
       
       list1 = solve(list1, list2);
       list2 = list2->next;
   }
    
    return list1;
}



