class Solution {
public:
    int scoreOfParentheses(string s) {
        stack<int>st;
        st.push(0);
        int ans=0;
        int n =s.length();
    for(int i =0;i <n;i++){
      if(s[i]=='('){ //depth increase
    st.push(0);
     }
        else if(!st.empty()&& s[i]==')'){
        int first=st.top();st.pop();
        int second=st.top();st.pop();
            int sum=max(2*first,1)+second;
            st.push(sum);
        }
    } ans=st.top();
        st.pop();
        return ans;
    }
};