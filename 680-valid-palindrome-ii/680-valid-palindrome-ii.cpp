class Solution {
public:
    bool helper(string s, int start , int end){
              while (start < end) {
            if (s[start] != s[end]) {
                return false;
            }start++;
            end--;
          }
        return true;
    }
    bool validPalindrome(string s) {
     int i=0;
     int j =s.length()-1;
        while(i<=j){
            if(s[i]!=s[j]){
            return (helper(s,i,j-1)||helper(s,i+1,j));
            }
            i++;
            j--;
           }return true;
    }
};