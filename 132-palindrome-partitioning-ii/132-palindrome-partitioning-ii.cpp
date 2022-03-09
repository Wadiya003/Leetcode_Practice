class Solution {
public:
    int minCut(string s) {
        int n=s.length();
        if(n<=1)return 0;
        int ans[n+1];
        for(int i=0; i<=n; ++i) ans[i] = i-1; //max cutsss
        for(int i=1;i<n;i++){
           for(int j=0;(i-j)>=0 && (i+j)<n && s[i-j]==s[i+j];j++){ //even 
               ans[i+j+1]=min(ans[i+j+1],ans[i-j]+1);
           }
            for(int j=0;(i-j-1)>=0 &&(i+j)<n &&s[i-j-1]==s[i+j];j++){ //odd
                ans[i+j+1]=min(ans[i+j+1],ans[i-j-1]+1);
            }
        }return ans[n];
    }
};
       
        
        
       
       

