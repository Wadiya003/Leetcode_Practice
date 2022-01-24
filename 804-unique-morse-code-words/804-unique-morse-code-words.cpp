class Solution {
public:
    int uniqueMorseRepresentations(vector<string>& words) {
        unordered_map<int,string>mp;
        unordered_set<string>st;
        vector<string> v{".-","-...","-.-.","-..",".","..-.","--.","....","..",".---","-.-",".-..","--","-.","---",".--.","--.-",".-.","...","-","..-","...-",".--","-..-","-.--","--.."};
        string temp="";
        for(int i=0;i<26;i++) mp[i]=v[i];
       
        for(int i=0;i<words.size();i++){
            string cur=words[i];
         for(auto &i:cur)temp+= mp[i-'a'];
            st.insert(temp);
            temp.clear();
        }
        return st.size();
    }
};