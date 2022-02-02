class Solution {
public://IDEA->SLIDING WINDOW ->HASHSET FIND ALL LETTERS
    vector<int> findAnagrams(string s, string p) {
    vector<int> ans;

    int m=s.length();
    int n=p.length();

        if(m<n)      
        return ans;
        
        vector<int> f_p(26,0);   
        vector<int> f_s(26,0);
        
                                 
        for(int i=0;i<n;i++)
        {
            f_p[p[i]-'a']++;
            f_s[s[i]-'a']++;
        }

        if(f_p ==f_s)
        ans.push_back(0); //first window
 
        for(int i=n;i<m;i++){
            f_s[s[i-n] - 'a']--;
            f_s[s[i] - 'a']++;

            if(f_p == f_s) ans.push_back(i-n+1);
        }
       
        
     return ans;
    }
};


 
        
        
       