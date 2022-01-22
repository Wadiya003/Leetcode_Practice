class Solution {
public:
    int lengthOfLongestSubstring(string s) {
         unordered_map <char,int> ma;

        int n=s.size();

        if(n<=1)

            return n;

        int m=0;

        int i=0,j=0;

        while(j<n)

        {

            

            if(ma[s[j]]>=1)

            {

                

                ma[s[i]]--;

                i++;

            }

            else

            {

                ma[s[j]]++;

                j++;

            }

            m=max(m,j-i);

        }

        return m;

    }
    
   
};