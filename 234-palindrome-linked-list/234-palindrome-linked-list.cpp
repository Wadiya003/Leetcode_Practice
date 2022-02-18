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
public://Reverse half list and compare
    //stack(half list put in stack then pop and compare with leftover )
    ListNode* reverse(ListNode* l){
        ListNode* pre=NULL;
        ListNode*cur=l;
        ListNode*next=NULL;
       while(cur!=NULL){
              // Store next
            next = cur->next;
  
            // Reverse current node's pointer
            cur->next = pre;
  
            // Move pointers one position ahead.
            pre = cur;
            cur= next;
}
        return pre;
}
    
     bool compareList(ListNode* head1, ListNode* head2){
        while(head1!=NULL && head2!=NULL){
            if(head1->val != head2->val) return false;
            head1=head1->next;
            head2=head2->next;
        }
        return true;
    }
    bool isPalindrome(ListNode* head) {
        if(head==NULL || head->next==NULL) return true;
        ListNode* slow=head,*fast=head;
        while(fast!=NULL && fast->next!=NULL){
            slow=slow->next;
            fast=fast->next;
            if(fast) fast=fast->next;
        } //return slow;
            
      ListNode* mid=reverse(slow);//reverse from mid till last
       return compareList(head,mid);

    }
};