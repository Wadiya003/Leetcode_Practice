class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        int m=s1.length();
        int n =s2.length();
        int tot=s3.length();
    
        vector<vector<bool>> dp(m+1,vector<bool>(n+1,false));
        if(m+n !=tot)return false;
        for(int i=m;i>=0;i--){
            for(int j=n;j>=0;j--){
                if(i==m&&j==n){
                    dp[i][j]=true;
                }
                 if ( i < m  && s1[i]==s3[i+j] && dp[i+1][j]){
                    dp[i][j]=true;
                }
                 if ( j < n  && s2[j]==s3[i+j] && dp[i][j+1]){
                    dp[i][j]=true;
                }
                
            }
            
        }
        return dp[0][0];
        
    }
};
               
        