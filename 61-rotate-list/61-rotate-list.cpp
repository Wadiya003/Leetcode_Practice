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
    ListNode* rotateRight(ListNode* head, int k) {
        int count=0;
       ListNode* temp=head;
        ListNode*prev,*temp2;
        
        if (k == 0 || !head)
			return head;
    
        while(temp){
        temp=temp->next;
        count++;}
         if (count == 1 || k % count== 0)
			return head;
    
        temp=head;
         k %= count;
        while(count-k){
         prev=temp;
        temp=temp->next;
        count--;}
        prev->next=NULL;//new last
        temp2= temp;   //new head;
        while(temp2->next){
        temp2=temp2->next;}
        temp2->next=head; //connect old tail to old head
        head=temp;
        return head;
    }
};
  
// 		 iter = head;
//         k %= num_nodes;
// 		// find node that will be head
//         while (num_nodes - k)
//         {
//             prev = iter;
//             iter = iter->next;
//             num_nodes--;
//         }
//         prev->next = NULL;
// 		// attach the previous tail to the previous head
//         iter2 = iter;
		
//         while (iter2->next)
// 			iter2 = iter2->next;
		
//         iter2->next = head;
//         head = iter;
    
//         return head;
     