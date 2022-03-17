class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        vector<int>ans;
        int n=s.length();
        int k=words.size();
        int l=words[0].size();
        int slide=k*l;
        unordered_map<string,int>m;
        for(string word:words){
        m[word]++;
        }
        int lastslide=n-slide;
        for(int i=0;i<=lastslide;i++){
         unordered_map<string,int> clone;
         int word=0;

        for(int j=i;j<i+slide;j+=l){
            string temp=s.substr(j,l);
            if(m[temp]>clone[temp]){
                clone[temp]++;
                word++;
            }
            else break;  
        }
        if(word==k) ans.push_back(i);
        }
        return ans;
    }
};
