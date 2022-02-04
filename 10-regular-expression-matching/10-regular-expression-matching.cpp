class Solution {
public:
    bool isMatch(string s, string p) {
    int n=p.size();
    int m=s.size();
    
    vector<vector<bool>>dp(n+1,vector<bool>(m+1));
    
    dp[0][0] = true; //when both are empty
    
    for(int j=1;j<=m;j++){
        dp[0][j]=false;//if pattern is empty
    }
    
    for(int i=1;i<=n;i++){ // iterate pattern 
        
        if(p[i-1]=='*') //if s empty but p is * => matches blank space
            dp[i][0]=dp[i-2][0];
        else  //if s empty
            dp[i][0]=false;
    }
    //main iteration
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            //simple if matches 
            if(p[i-1]=='.' or p[i-1]==s[j-1])
            { dp[i][j]=dp[i-1][j-1];}
            
            //if its a star=> use it or not use it
            else if(p[i-1]=='*'){
                
                // in case previous element is same 
                if(p[i-2]=='.' or p[i-2]==s[j-1]){
                    // use it and move on OR use it for more chars
                    dp[i][j]=dp[i-2][j] or dp[i][j-1];
                }
                else{ //if previous doesnt match then use it and stay in that pos 
                    dp[i][j]=dp[i-2][j];                        
                }
            }
            
        }
    }
    
    return dp[n][m];
    }
};