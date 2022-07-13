class Solution {
public:
    string minWindow(string s, string t) {
        int n=s.length();
        unordered_map<int,int>m;
        unordered_map<int,int>window;
        for(auto a:t){
        m[a]++;
        }
        int compare=INT_MAX;
        string result;
        int have=0;
        int need=t.length();
        for(int j = 0, i = 0; i < n; i++){
            char c=s[i];
            if(m.find(c) != m.end()){
            window[c]++;
                if(window[c] <= m[c]){
                have++;
                }
            }

        
             if(have >= need){
             while (m.find(s[j]) == m.end() || window[s[j]] > m[s[j]])
            {
                window[s[j]]--;
                j++;
            }
            if(i-j + 1 <compare){
                compare = i - j + 1;
                result = s.substr(j, compare);
            }
        }
    }
        return result; 
        
    }
};