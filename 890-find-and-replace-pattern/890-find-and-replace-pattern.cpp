class Solution {
public:
    vector<string> findAndReplacePattern(vector<string>& words, string pattern) {
      vector<string>ans;
      for(auto word:words){
          // if(pattern.compare(word)==0)
          //     ans.push_back(word);
          if(helper(word,pattern)&& helper(pattern,word)){
              ans.push_back(word);}
      }return ans;
    }   //using one map
      bool helper(string words, string pattern){
      unordered_map<char,char>mp;
          for(int i=0;i<words.length();i++){
              if(mp[words[i]]){
                  if(mp[words[i]]!=pattern[i])
                      return false;
              }
              else {
                  mp[words[i]]=pattern[i];
              }
          }
      return true;
      }
    
        //using two maps
//     bool helper(string words, string pattern){
//         unordered_map<char,char>m1;
//         unordered_map<char,char>m2;
//         for(int i=0;i<words.length();i++){
//             char w=words[i];
//             char p=pattern[i];
//             if(m1.find(w)==m1.end())m1[w]=p;
//             if(m2.find(p)==m2.end())m2[p]=w;
//             if(m1[w]!=p || m2[p]!=w){
//             return false;}
//         }return true;
// }
};