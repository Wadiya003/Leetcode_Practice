/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:
    vector<int> postorder(Node* root) {
           vector<int> ans;
        if(!root)
        return ans;
        stack< Node*>st;
        st.push(root);
        while(!st.empty()){
            Node* curr=st.top();
            int size = curr->children.size();
            if(size){
                while(size--){
                    st.push(curr->children[size]);
                }
               curr->children.clear();
            }
            else{
                ans.push_back(curr->val);
				
                st.pop();
        }}return ans;
    }
};