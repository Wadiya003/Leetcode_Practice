class Solution {
public:
    char findTheDifference(string s, string t) {
       unordered_map<char,int>m;
        for(int i=0;i<t.size();i++)
            m[t[i]]++;
        for(int i=0;i<s.size();i++)
            m[s[i]]--;
      for(auto it:m){
          if(it.second==1)
              return it.first;
      }
        return ' ';
    }
};