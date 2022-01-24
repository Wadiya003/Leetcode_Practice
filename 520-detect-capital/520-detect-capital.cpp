class Solution {
public:
   bool cap(string s)
    {
        for(int i = 0; i < s.size(); i++)
        {
            if(s[i] < 'A' || s[i] > 'Z')
            {
                return false;
            }
        }
        return true;
    }
    
    bool lo(string s)
    {
        for(int i = 0; i < s.size(); i++)
        {
            if(s[i] < 'a' || s[i] > 'z')
            {
                return false;
            }
        }
        return true;
    }
    
    
    
    bool mix(string s)
    {
        if(s[0] >= 'A' && s[0] <= 'Z')
        {
            for(int i = 1; i < s.size(); i++)
            {
                if(s[i] < 'a' || s[i] > 'z')
                {
                    return false;
                }
            }
            return true;
        }
        return false;     
    }
    
    
    bool detectCapitalUse(string s) {
        
        if(cap(s) || lo(s) || mix(s))
        {
            return true;
        }
        return false;     
    }

    
};