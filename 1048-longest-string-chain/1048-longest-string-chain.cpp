class Solution {
public://IDEA->delete one word each time ,find if the word exits in map or not 
    int longestStrChain(vector<string>& words) {
        map<string,int>mp;
        
        for(auto word : words){
            mp[word]=1;//each word itself is a valid ans
        }
        
         sort ( words.begin(), words.end(), [](const string &a, const string &b) { 
            return a.size() > b.size();
        });
        
         for(auto word:words){
             for(int i =0;i<word.size();i++){
                 string temp=word;
                 temp.erase(temp.begin()+i); //delete words 
                 mp[temp]=max(mp[temp],1+mp[word]); //update in map 
             }
         }
        
          int ans = 0;
        for ( auto u : words ) ans = max ( ans, mp[u] ); //return the highest value 
        return ans;
    }
};
  
  
       