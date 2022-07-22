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
    ListNode* partition(ListNode* head, int x) {
       ListNode* b=new ListNode(0); 
        ListNode* ptr1=b;
      ListNode* a=new ListNode(0);
        ListNode* ptr2=a;
        if(head==NULL)return nullptr;
        while(head){
        if(head->val<x){
        ptr1->next=head;
        ptr1=ptr1->next;}
        else {
            ptr2->next=head;
            ptr2=ptr2->next;
        }head=head->next;
        }
        ptr2->next=NULL;
        ptr1->next=a->next;
        
      
        return b->next;
    }
    
};