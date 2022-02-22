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
public://Intuitive 
    ListNode* mergeNodes(ListNode* head) {
        ListNode* dummy=new ListNode(0,nullptr);
        ListNode* merge=dummy;
        int sum=0;
        ListNode *temp = head;
        while(temp){
        if(temp->val==0 && sum!=0 ){
            merge->next=new ListNode(sum,nullptr);
            merge=merge->next;
            sum=0;
         }
            else{
               
                sum+=temp->val;
                 temp=temp->next;
            }
        
        }
        return dummy->next;
    }
};
  
             