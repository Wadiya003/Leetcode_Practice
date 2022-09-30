class Solution {
public:
    vector<vector<int>> getSkyline(vector<vector<int>>& buildings) {
        vector<vector<int>> v;
        map<int, vector<pair<int, int>>> map; 
        for (auto& building : buildings) {
            map[building[0]].push_back({building[2], 0}); 
            map[building[1]].push_back({building[2], 1}); 
        }
        multiset<int> ms;
        for (auto& m : map) {
            int pos=m.first;
            vector<pair<int,int>>heights=m.second;
            for (auto& h : heights) {
                int height=h.first;
                int type=h.second;
                if (type == 0) 
                    ms.insert(height);
                else 
                    ms.erase(ms.find(height));
            }
            int newHeight = ms.empty() ? 0 : *ms.rbegin();
            if (!v.empty() && v.back()[1] == newHeight) 
                continue;
            else 
                v.push_back(vector<int>({pos, newHeight}));
        }
        return v;
    }
};