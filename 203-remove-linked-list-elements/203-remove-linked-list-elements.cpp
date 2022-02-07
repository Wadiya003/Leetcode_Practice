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
    ListNode* removeElements(ListNode* head, int val) {
        ListNode* prev =NULL ;
        ListNode* temp =head;
         if(head==NULL){
            return NULL;
        }
        while(temp!=NULL){
               if(head->val == val){
                head = head->next;
            }
            if(temp->val == val && prev != NULL){
                prev->next = temp->next;
                temp= prev->next;
            }else{
                prev = temp;
                 temp = temp->next;
            }
            

        }return head;
    }
};