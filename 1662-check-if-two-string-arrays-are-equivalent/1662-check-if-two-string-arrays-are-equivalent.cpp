class Solution {
public:
    bool arrayStringsAreEqual(vector<string>& word1, vector<string>& word2) {
        string ans,anss;
        for(auto a:word1){
            ans+=a;
        }
        for(auto a:word2){
            anss+=a;
        }
        return ans==anss;
    }
};