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
public://using stacks
    void reorderList(ListNode* head) {
        if(!head || !head->next || !head->next->next)return;
        ListNode* temp=head;
        stack<ListNode*> st;
        //push all nodes in stack 
        while(temp){
         st.push(temp);
        temp=temp->next;
        }
        int size=st.size();
        ListNode* tempo=head;
        //connect
        for(int i =0;i< size/2;i++){
        ListNode* last=st.top();
        st.pop();
        last->next=tempo->next;
        tempo->next=last;
        tempo=tempo->next->next;
        }
          
        tempo->next=NULL;
        return;
        
    }
};