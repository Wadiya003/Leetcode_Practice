class Solution {
public:
    string reverseWords(string s) {
        int i = 0;
        for (int j = 0; j < s.size(); ++j) {
            if (s[j] == ' ') {
                //handle space
                reverse(s.begin() + i, s.begin() + j);//reverse word
                i = j + 1;
            }
        }
        reverse(s.begin() + i, s.end());//reverse whole sentence with reverse words
        return s;
    }
};