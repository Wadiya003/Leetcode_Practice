class Solution {
public:
    bool isValid(string s) {
           stack<char> st;
        int n = s.size();
        if(n == 1) return false;
        for(int i = 0; i < n; i++){
            if(st.empty() && (s[i] == ')' || s[i] == ']' || s[i] == '}')) return false;
            else if(s[i] == '(' || s[i] == '[' || s[i] == '{') st.push(s[i]);
            else{
                if(s[i] == ')' && (st.top() == '[' || st.top() == '{')) return false;
                else if(s[i] == ']' && (st.top() == '(' || st.top() == '{')) return false;
                else if(s[i] == '}' && (st.top() == '(' || st.top() == '[')) return false;
                st.pop();
            }
        }
        return (st.empty() ? true : false);
    }
    
};