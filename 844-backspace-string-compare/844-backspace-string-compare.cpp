class Solution {
public:
    bool backspaceCompare(string s, string t) {
          int l1=0,l2=0;
        for(int i=0;i<s.size();i++)
        {
            if(s[i]=='#'){
                l1--;
                 l1=max(0,l1);
            } 
           else{
               s[l1]=s[i];
               l1++;
           }
        }
        for(int i=0;i<t.size();i++)
        {
            if(t[i]=='#'){
                l2--;
                 l2=max(0,l2);
            }
           else{
               t[l2]=t[i];
               l2++;
           }
        }
        if(l1!=l2) return false;
        else{
            for(int i=0;i<l1;i++)
            {
                if(s[i]!=t[i])
                    return false;
            }
            return true;}
        
    }
};