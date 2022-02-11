class Solution {
public: //sliding window technique
    ///Frequency must be same 
    bool checkInclusion(string s1, string s2) {
      if(s1.size()>s2.size())return false;  
        vector<int>Hs1(26,0);
        vector<int>Hs2(26,0);
        for(auto i:s1){
        Hs1[i-'a']++;
        }
        for(int i =0;i<s1.size();i++){
        Hs2[s2[i]-'a']++;
        }
        for(int i=1;i<=s2.size()-s1.size();i++){
         if(Hs1==Hs2)return true;
         Hs2[s2[i-1]-'a']--;
         Hs2[s2[i+s1.size()-1]-'a']++;
        }
        if(Hs1==Hs2)return true;
        return false;
    }
    
};

  