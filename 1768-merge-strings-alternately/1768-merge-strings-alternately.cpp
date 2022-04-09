class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        int i =0;
        int j =0;
        string tmp="";
        while(i < word1.length() && j < word2.length()){
           tmp+=word1[i++];
            tmp+=word2[j++];
        }
        if(i!=word1.length()){
           while(i<word1.length()){
            tmp+=word1[i];
           i++;}}
        if(j!=word2.length()){
           while(j<word2.length()){
            tmp+=word2[j];
           j++;}}
        return tmp;
    }
};