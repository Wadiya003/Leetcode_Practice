class Solution {
public:
    bool isMatch(string s, string p) {
        int m =s.length();
        int n =p.length();
        int i =0,j=0;
        vector<vector<int>>dp(m+1,vector<int>(n+1,0));
        dp[0][0]=1;
         for(int i=1; i<=n; i++){
            if(p[i-1] == '*') dp[0][i] = 1;
            else break;
        }
        for(i =0;i<m;i++){
          for(j=0;j<n;j++){
           if(p[j] == '*') {
            dp[i+1][j+1] = dp[i+1][j] || dp[i][j+1];
             } else {
            dp[i+1][j+1] = dp[i][j] && (s[i] == p[j] || p[j] == '?');
                }}}
        return dp.back().back();
    }
};