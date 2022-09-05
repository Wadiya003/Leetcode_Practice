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
    vector<vector<int>> levelOrder(Node* root) {

        if(root==NULL){
            return {};
        }
           vector<vector<int>> a;
        queue<Node*>q;
        q.push(root);
        while(!q.empty()){
            vector<int>v;
            int sz=q.size();
            for(int i=0;i<sz;i++){
                Node* tp=q.front();
                q.pop();
                v.push_back(tp->val);
                if(tp->children.size()){
                  for(int j=0;j<tp->children.size();j++){
                      q.push(tp->children[j]);
                  }
                }   
            } 
         a.push_back(v);
        }
        return a;
    
    }
};