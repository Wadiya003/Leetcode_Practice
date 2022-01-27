class Solution {
public:
    bool divisorGame(int n) {
        vector<int> dp(n+1,0);
         if(n==1)return false;
          for(int i=2;i<=n;i++){
              for(int j=1;j<=sqrt(i);j++){
                  if(i%j==0 &&dp[i-j]==0) //win condition at i only if bob loses at j-i;
                  {
                  dp[i]=1; 
                  }
              } 
          }
        
        if(dp[n]==1)return true;
              return false;
          }
        

    
};
 