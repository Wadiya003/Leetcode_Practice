class Solution {
public:
vector<string>roman= {"M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I"};
 vector<int>dec = {1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1};
    string intToRoman(int num) {
        string ans;
        for(int i=0; num != 0; i++)
        {
            while(num >= dec[i])
            {
                num -= dec[i];
                ans += roman[i];
            }
        }
        
        return ans;

    }
};