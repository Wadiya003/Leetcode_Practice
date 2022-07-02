class Solution {
public:
    int longestPalindrome(vector<string>& words) {
        int ans=0,used=0;
        map<string,int> m;
        for(auto w:words) {
            m[w]++;
        }
        for(auto x:words) {
            string w=x;
            reverse(w.begin(),w.end());
            if(w!=x && m[x]>0 && m[w]>0) {
                m[x]--;
                m[w]--;
                ans+=4;
            }
            else if(w==x && m[x]>1) {
                m[x]-=2;
                ans+=4;
            }
            else if(w==x && m[x]>0 && used!=1 ) {
                used=1;
                m[x]--;
                ans+=2;
            }
        }
        return ans;
        
    }
};