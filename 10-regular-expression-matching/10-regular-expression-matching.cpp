class Solution {
public:
    bool isMatch(string s, string p) {
   //top-down 
    vector<vector<int>> dp(s.length()+2,vector<int>(p.length()+2,0));
  return helper(s,p,0,0,dp);
   }
    
    
    bool helper(string &s, string &p, int i ,int j,vector<vector<int>>&dp){
    int n=s.length();
    int m=p.length();
    
    if(i>=n && j>= m)return true;
    if(j>=m)return false;
    if(dp[i][j]){
    return dp[i][j];}
    
        
//      if(j==m){
//         dp[i][j]=i==s.length();
//         return (i==s.length());
//      }
        
     //handling char match and .
      
          bool match=(i<n && (s[i]==p[j] || p[j]=='.'));
          //handling * sign
         if((j+1)<m && p[j+1]=='*'){
             int opt1=helper(s,p,i,j+2,dp);//do not use star
             int opt2=match && helper(s,p,i+1,j,dp);//if char matches at j and we use star
           return dp[i][j]=(opt1||opt2);
         }
         if (match){
           return dp[i][j]= helper(s,p,i+1,j+1,dp);
         }
         else
           return dp[i][j]=false;
 }
};