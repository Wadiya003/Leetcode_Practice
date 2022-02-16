class Solution {
public://frequency should be same 
    //OR just sort the string an dmake it the key for map
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
  unordered_map<string,vector<string>>m;
    vector<vector<string>>ans;
        for(auto& s:strs){
         string temp=s;
         sort(temp.begin(),temp.end());
         m[temp].push_back(s);     
        }
        for(auto& i:m){
            ans.push_back(i.second);
        }return ans;
    }
};