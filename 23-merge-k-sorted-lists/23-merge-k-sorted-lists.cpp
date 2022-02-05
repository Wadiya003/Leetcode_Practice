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
public:   //mergesort O(N * log(K))
    
        ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
         ListNode *temp;
         if (l1 == NULL)
        {
            return l2;
        }
        if (l2 == NULL)
        {
            return l1;
        }
        
        if (l1->val < l2->val)
        {
            temp = l1;
            temp->next = mergeTwoLists(l1->next, l2);
        }
        else
        {
            temp = l2;
            temp->next = mergeTwoLists(l1, l2->next);
        }
        return temp;
    }
    ListNode* mergeKLists(vector<ListNode*>& lists) {
      
      int l=lists.size();
        if(l==0)return NULL;
      return mergelists(lists,0,l-1);
     
    }
    ListNode* mergelists(vector<ListNode*>& lists,int start , int end){
        if (start==end )return lists[start];
        int mid=start+(end-start)/2;
        ListNode* left=mergelists(lists,start, mid);
        ListNode* right=mergelists(lists,mid+1,end);
        return mergeTwoLists(left,right);
    }
};