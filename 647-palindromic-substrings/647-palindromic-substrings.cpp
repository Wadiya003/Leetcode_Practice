class Solution {
public:
    int countSubstrings(string s) {
      int l=0,r=0,res=0;
        for(int i=0;i<s.length();i++){
            l=r=i;
            //odd size
            while(l>=0 and r<s.length() &&s[l]==s[r]){
            res+=1;
            l--;
            r++;}
            //even size
            l=i;
            r=i+1;
            while(l>=0 and r<s.length() &&s[l]==s[r]){
            res+=1;
            l--;
            r++;}
        }return res;
    }
};