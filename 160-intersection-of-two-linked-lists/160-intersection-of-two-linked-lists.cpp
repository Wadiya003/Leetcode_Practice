/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public://diffrence in length approach
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        int m=0, n =0;
        ListNode* ptr1=headA;
        ListNode* ptr2=headB;
        while(ptr1!=NULL){
            ptr1=ptr1->next;
            ++m;
        }
          while(ptr2!=NULL){
            ptr2=ptr2->next;
            ++n;
        }
        int diff=abs(m-n);
        if(m>n){
            while(diff)
            {
				headA = headA -> next;
				diff--;
			}
            }
            
        else{
            while(diff)
            {
               headB =headB->next;
            diff--;
            }
            }
        	while(headA != NULL and headB != NULL){
			if(headA == headB){
				return headA;
			}
			headA = headA -> next;
			headB = headB -> next;
		}
		return NULL;
	
        
    }
};
