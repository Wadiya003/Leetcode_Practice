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
    ListNode* swapNodes(ListNode* head, int k) {
        ListNode *front=head;
        ListNode* back=head;
        ListNode* temp=head;

        if(!head){
        return nullptr;
        }
        int cnt = 1;
        while(temp!=NULL){
            if (cnt<k){
                front = front->next;
            }
            if (cnt>k){
                back = back->next;
            }
         temp = temp->next;
            cnt++;
        }
          int swapp=front->val;
          front->val=back->val;
          back->val=swapp;
         return head;
    }
    
};