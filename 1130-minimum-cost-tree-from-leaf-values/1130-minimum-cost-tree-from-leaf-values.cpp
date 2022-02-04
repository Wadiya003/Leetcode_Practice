class Solution {
public:
    int mctFromLeafValues(vector<int>& arr) {
        int n=arr.size();
        int sum=0;
        int pro;
        stack <int> st;
        for(auto a: arr){
        while(!st.empty() && a>st.top()){
            pro=st.top();
            st.pop();
            if(st.empty()) sum+=pro*a;
            else sum+=pro*(min(st.top(),a));
        }st.push(a);
        }
        while(!st.empty()){
            pro=st.top();
            st.pop();
            if (!st.empty()) sum += st.top()*pro;
       }
        
        return sum;
    }
};
 
       