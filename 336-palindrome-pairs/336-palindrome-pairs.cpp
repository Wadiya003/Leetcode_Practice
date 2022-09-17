class Solution {
public:
     bool isPalindrome(string str, int s, int e)
     {
        while(s < e)
        {
            if(str[s++] != str[e--])
                return false;
        }
        return true;
    }
    vector<vector<int>> palindromePairs(vector<string>& words) {
        vector<vector<int>>ans;
        int n=words.size();
        set<int>s;
        map<string,int>m;
        for(int i=0;i<n;i++)
        {
         m[words[i]]=i;
         s.insert(words[i].size());
        }
        for(int i=0;i<n;i++){
         int l=words[i].size();
            
            if(l==1){
                //case for blank space 
                if(m.count("") && m[""] != i)
                {
                    ans.push_back({i, m[""]});
                    ans.push_back({m[""], i});
                }
                continue;
            }
            //case : when str1 is rev of str2
            string r= words[i];
            reverse(r.begin(), r.end());
            
        
            if(m.count(r) && m[r] != i)
            {
                ans.push_back({i, m[r]});
            }
            //cases like lls and sssll
            for(auto ss:s){
                if(l==ss)
                    break;
                // prefix
                if(isPalindrome(r, 0, l - 1 - ss))
                {
                    string str1 = r.substr(l-ss);
                    if(m.count(str1))
                    {
                        ans.push_back({i, m[str1]});
                    }
                }
                
                // suffix
                if(isPalindrome(r, ss, l - 1))
                {
                    string str2 = r.substr(0, ss);
                    
                    if(m.count(str2))
                    {
                        ans.push_back({m[str2], i});
                    }
                }
            }
        }
        return ans;
    }
};