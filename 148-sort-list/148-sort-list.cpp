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
public://merge sort=>O{NlogN}
    
    //find mid for each part
    ListNode* findmid(ListNode* head){
    ListNode* temp=nullptr;
        //slow and fast technique
    while(head && head->next){
    temp=(temp==nullptr)?head:temp->next;
    head=head->next->next;
    }
    ListNode* mid=temp->next;
        temp->next=nullptr;
        return mid;
    }
    
    //merge sorted parts 
    ListNode* mergesort(ListNode* list1, ListNode* list2){
        ListNode * temp=new ListNode(0);
        ListNode * ptr = temp;
        while(list1 && list2){
        if( list1->val < list2->val){
            ptr->next=list1;
            list1=list1->next;
          }
        else{
            ptr->next=list2;
            list2=list2->next;   
        }
            ptr=ptr->next;
        }
        //if any list remaining
        if (list1){
          ptr->next=list1;
        }
         else{
          ptr->next=list2;
        }
        return temp->next;
        free(temp);
        
    }
    
    
    //main
    ListNode* sortList(ListNode* head) {
      //Base Case
        if(!head || !head->next){
        return head;}
        ListNode* mid=findmid(head);
        ListNode* left=sortList(head);
        ListNode* right=sortList(mid); 
        return mergesort(left, right);
    }
};