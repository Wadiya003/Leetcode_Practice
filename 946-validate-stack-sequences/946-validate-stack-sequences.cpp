class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        stack<int>s;
        int i=0,j=0;
        while(i<popped.size()){
            if((s.empty()||s.top()!=popped[i])&& j<pushed.size()){
                s.push(pushed[j++]);

            }
            else if(s.top()==popped[i]){
                s.pop();i++;
            }
            else{
                break;
            }
       }
        return s.empty()?1:0;
    }
};
 