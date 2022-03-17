class Solution {
public:
    string minRemoveToMakeValid(string s) {
      int n =s.length();
        stack<int>st;
        int i=0;
         while(i<n){
        if (s[i] == '(')st.push(i);
        if (s[i] == ')'){
        if (!st.empty()) st.pop();
        else s[i] = '-';
         }
             i++;
         }
        while(!st.empty()){ 
     s[st.top()]='-';

        st.pop();
        }
         
        string temp="";
        for (int i =0;i<n;i++){
            if(s[i]=='-'){
                continue;
            }
            else{
                temp.push_back(s[i]);
 }
}return temp; 
        
    }
};