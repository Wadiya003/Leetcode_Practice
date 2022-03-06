class Solution {
public:
    string reverseParentheses(string s) {
        int n =s.length();
        stack<char>st;
        for(int i =0;i<n ;i++)
          if(s[i]!=')')
          st.push(s[i]);
         
            else{
                string t="";
               while(!st.empty() and st.top()!='('){
               t+=st.top();
               st.pop();}
               st.pop();
                for(int j=0;j<t.size();j++){
                      st.push(t[j]); 
              }
               
            }
            s.clear();
            while(!st.empty()){
            s+=st.top();
            st.pop();
            }
        
          
     reverse(s.begin(),s.end());
        return s;
    }
      
};
