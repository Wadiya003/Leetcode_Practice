class Solution {
public:
    string simplifyPath(string path) {
        string s;
        stack<string> st;
        int n=path.length();
       for(int i =0;i< n;i++){
           if(path[i]=='/')continue;
           string temp;
           while(i<n&&path[i]!='/'){
               temp+=path[i];
               i++;
           }
           if(temp==".")continue;
           else if(temp==".."){
           if(!st.empty()){
            st.pop();
               }
             }
           else{
             st.push(temp);
           }
       }
        
    while(!st.empty()){
        
            s = "/" + st.top() + s;
            st.pop();
        
    }
     if(s.size() == 0)
            return "/";
        
       return s;
    }
};
 
       