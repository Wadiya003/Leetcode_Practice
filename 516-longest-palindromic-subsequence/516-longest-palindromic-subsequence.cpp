class Solution {
public:
    //recursion
    int ans=1;
    int dp[1001][1001];
    int longestPalindromeSubseq(string s) {
        memset(dp,-1,sizeof(dp));
    int n=s.length();
        if(n==1){
            return 1;
        }
     return recursion(0,n-1,s);
    }
    
int recursion(int start, int end,string &s){
   if(start==end){
       return ans;
   }
  if(start>end)return 0;
 if(dp[start][end]!=-1)
            return dp[start][end];
   return dp[start][end]=(s[start]==s[end])? 2+recursion(start+1,end-1,s):  max(recursion(start+1,end,s),recursion(start,end-1,s)); 
   }
};