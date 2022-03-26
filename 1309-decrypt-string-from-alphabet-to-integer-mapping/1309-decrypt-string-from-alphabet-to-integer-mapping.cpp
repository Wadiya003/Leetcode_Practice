class Solution {
public:
    string freqAlphabets(string s) {
        string res;
        for(int i=0;i<s.length();i++){
            if(i<s.length()-2 &&s[i+2]=='#'){
                res += 'j' + (s[i] - '1') * 10 + s[i + 1] - '0';
                i+=2;
              }
            else{
                res+='a' +(s[i] - '1');
            }
        }return res;
    }
};