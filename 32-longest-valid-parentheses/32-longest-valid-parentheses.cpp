class Solution {
public:
    int longestValidParentheses(string s) {
        stack<int>st;
        st.push(-1);
        int len=0,count=0;
        for(int i=0;i< s.length();i++){
      
            if(s[i]=='(')
           st.push(i);
        
        else {
            st.pop();
            if(st.empty()){
             st.push(i);}
            else {
         count=i-st.top();
         len=max(count,len);}
       }
        } return len;
        
    }
};