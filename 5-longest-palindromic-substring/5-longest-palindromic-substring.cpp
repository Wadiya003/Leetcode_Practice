class Solution {
public:
    string longestPalindrome(string s) {
        string res;
        for( int i =0;i<s.length();i++){
        
            //odd length palindrome
            int left = i;
            int right = i;
            while(left>=0 && right < s.size() && s[left] == s[right])
            {
                if( (right-left+1)>res.length() )
                {
                    //this is our new potention answer
                    res.erase();
                    res.append(s.substr(left, right-left+1));
                }
                left--; right++;
            }
    
            //even length palindrome
            left = i;
            right = i+1;
            while(left>=0 && right < s.size() && s[left] == s[right])
            {
                if( (right-left+1)>res.length())
                {
                    //this is our new potention answer
                    res.erase();
                    res.append(s.substr(left, right-left+1));
                }
                left--; right++;
                
            }
        
        }
        return res;
    
    }
};