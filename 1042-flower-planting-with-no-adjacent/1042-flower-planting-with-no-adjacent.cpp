class Solution {
public:
    vector<int> gardenNoAdj(int n, vector<vector<int>>& paths) {
    vector<int> res(n);
    vector<vector<int>> g(n);
    for (auto p : paths) {
    g[p[0] - 1].push_back(p[1] - 1);
    g[p[1] - 1].push_back(p[0] - 1);
    }
   for (auto i = 0; i < n; ++i) {
    bool used[5] = {};
    for (auto j : g[i]) 
        used[res[j]] = true;
    for (auto k = 1; k <= 4; ++k) {
      if (!used[k]) 
          res[i] = k;
    }
  }
  return res;  
    }
};