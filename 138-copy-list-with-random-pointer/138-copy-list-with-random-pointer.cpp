/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        if(!head)return head;
        Node* clone=new Node(head->val, nullptr, nullptr);
        Node* oldhead=head;
        Node* newhead=clone;
        unordered_map<Node*,Node*>connect;
        connect[oldhead]=newhead;
        //make clone nodes 
        while(oldhead->next){
        newhead->next = new Node(oldhead->next->val, nullptr, nullptr);
        newhead = newhead->next;
        oldhead = oldhead->next;
        connect[oldhead] = newhead;
       
        } oldhead=head;
          newhead=clone; 
        //make old connection
        while(oldhead && newhead){
            newhead->random=oldhead->random?connect[oldhead->random]:nullptr;
            oldhead=oldhead->next;
            newhead=newhead->next;
        }
        return clone;
    }
};