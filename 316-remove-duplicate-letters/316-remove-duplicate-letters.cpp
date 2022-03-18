class Solution {
public:
    string removeDuplicateLetters(string s) {
     vector<bool> seen(26, false); 
      stack<char>st;
        string ans="";
      vector<int> last(26, 0);
        for (int i = 0; i < s.length(); i++){
            last[s[i] - 'a'] = i;
        }
        
     for(int i =0;i<s.length();i++){
             if(seen[s[i]-'a']) continue; 
            while(st.size() > 0 && st.top() > s[i] && i < last[st.top() - 'a']){
                seen[st.top() - 'a'] = false; 
                st.pop();
            }
            st.push(s[i]);
            seen[s[i]-'a'] = true; 
     }
        while(!st.empty()){
      ans+=st.top();
        st.pop();
        }
        reverse(ans.begin(),ans.end());
         return ans;
    
    }
};