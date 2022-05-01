class Solution {
public: 
   long long solve(char c, string s){ 
        long long cnt=0,res=0;
        long long n=s.length();
        for(int i=0;i<n;i++){
            if(s[i]==c){
                res+=(cnt)*(cnt+1)/2;
                cnt=0;
            }
            else
                cnt++;
        }
        res+=(cnt)*(cnt+1)/2;
        return n*(n+1)/2 - res;
    }
    long long appealSum(string s) {
        long long ans=0;
        for(char c='a';c<='z';c++)
            ans+=solve(c,s);
          return ans;
    }
};