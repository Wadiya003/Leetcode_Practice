// int dp[101][101][30][11];
class Solution {
public:
    //recursion + memo
    //dp[ind][k]
    int dp[101][101];
    int dfs(string &s, int ind, int K) {
        int k = K;
        if(s.size() - ind <= k) 
            return 0;
        if(dp[ind][k] >= 0) 
            return dp[ind][k];
        //delete one char
        int res = k ? dfs(s, ind+ 1, k - 1) : 101, len = 1;
        
        for(int i = ind + 1; i <= s.size(); ++i) {
        //concat or keep
        res = min(res, dfs(s, i, k) + 1 + (len >= 100 ? 3 : (len >= 10 ? 2 : (len > 1 ? 1 :0))));
        if(i == s.size()) 
            break;
        if(s[i] == s[ind]) 
            ++len;
        else if(--k < 0) 
            break;
        }
        return dp[ind][K] = res;
    }
    
    int getLengthOfOptimalCompression(string s, int k) {
        int ind=0;
        int len=0; 
        const int N = s.size();
        memset(dp, -1, sizeof dp);
        return dfs(s,0,k);
    }
    // int helper(string s, int ind, int k, int len, int ch){
    //     int ans=101;//max ans we can get
    //     if(k<0){
    //         return 101;
    //     }
    //     if(len>=s.length()){
    //         return 0;
    //     }
    //     if(dp[ind][k][len][ch]!=-1){
    //         return dp[ind][k][len][ch];
    //     }
    //     //delete current
    //     ans= min(ans,helper(s,ind+1,k-1,len,ch));
    //     //concat
    //     if(s[ind]-'a'==ch){
    //         //can concat
    //         if(len==1 || len==9|| len==99){
    //             //concat will result in len+1
    //             ans=min(ans,1+helper(s,ind+1,k,min(10,len+1),ch));
    //         }
    //         else{
    //             //concat won't change length
    //             ans=min(ans,helper(s,ind+1,k,min(10,len+1),ch));
    //         }
    //     }
    //     //keep
    //     else{
    //         ans=min(ans,1+helper(s,ind+1,k,1,s[ind]-'a'));
    //     }
    //     return dp[ind][k][len][ch]=ans;
    // }
};
