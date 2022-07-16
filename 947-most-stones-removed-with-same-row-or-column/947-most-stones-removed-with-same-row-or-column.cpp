class Solution {
public:
     int dfs(unordered_map<int,vector<int>> &row, unordered_map<int,vector<int>>&col, unordered_set<int> &s, int r) {
     auto res = 0;
     if (s.insert(r).second){
          res += row[r].size();
     for (auto c : row[r])
       for (auto r : col[c]) 
          res += dfs(row, col, s, r);
      }
       return res;
     }
     int removeStones(vector<vector<int>>& stones) {
      unordered_map<int, vector<int>> row, col;
      unordered_set<int> s;
      auto res = 0;
      for (auto s : stones) 
          row[s[0]].push_back(s[1]), col[s[1]].push_back(s[0]);
      for (auto r : row) 
            res += max(0, dfs(row, col, s, r.first) - 1);
       return res;
    }
};