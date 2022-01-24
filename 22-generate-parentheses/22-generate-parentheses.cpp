class Solution {
public:   vector<string>ans;
    vector<string> generateParenthesis(int n) {
      
        backtrack(0,0,"",n);
        return ans;
    }
    void backtrack(int open,int close,string cur,int n){
        if(open==n && close==n)
        ans.push_back(cur);
      
        if(open < n) backtrack(open+1, close,cur+'(', n);
        if(close < open) backtrack(open, close+1,cur+')', n);
    }
};