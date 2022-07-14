class Solution {
public:
    int calculate(string s) {
        stack<int>st;
        int ans=0;
        s += '+';
        int l=s.size();
        if(l==0)return 0;
        char sign='+';
        for(auto a :s){
          if(isdigit(a)){
          ans=ans*10 + (a-'0');
          }  
            else if(a!=' '){
                if(sign == '-'){
                    st.push(ans*(-1));
                }
                else if(sign == '+'){
                    st.push(ans);
                }
                else if(sign == '/'){
                    int t=st.top();
                    st.pop();
                    st.push(t/ans);
                }
                else if(sign == '*'){
                    int t=st.top();
                    st.pop();
                    st.push(t*ans);
                }
               ans=0;
               sign=a; 
            }
        }
        int res=0;
        while(!st.empty() ){
        res+=st.top();
        st.pop();}
        return res;
        
        
    }
};