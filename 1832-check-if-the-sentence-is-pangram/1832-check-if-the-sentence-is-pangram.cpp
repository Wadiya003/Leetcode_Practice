class Solution {
public:
    bool checkIfPangram(string sentence) {
        set<char>s;
        for(auto a:sentence){
            s.insert(a);
        }
        return s.size()==26;
    }
};