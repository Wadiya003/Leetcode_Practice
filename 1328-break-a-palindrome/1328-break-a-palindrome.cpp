class Solution {
public:
    //greedy
    string breakPalindrome(string palindrome) {
        if(palindrome.size()==1){
            return "";
        }
        int n=palindrome.length();
        for(int i=0;i<n;i++)
        {
            if(n%2!=0 && i==n/2) 
                continue; 
            else if(palindrome[i]!='a') 
            {
                palindrome[i]='a'; 
                return palindrome;  
            }
            if(palindrome[i]=='a' && i==n-1) 
                palindrome[i]='b'; 
        }
        return palindrome;
    }
};