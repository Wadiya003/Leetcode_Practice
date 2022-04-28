class Solution {
public:
    const int xdir[4] = {-1,0,1,0}, ydir[4] = {0,1,0,-1};
    
    int minimumEffortPath(vector<vector<int>>& heights) {
        int n = heights.size(), m = heights[0].size();
        priority_queue <pair<int,pair<int,int>>, vector<pair<int,pair<int,int>>>, greater<pair<int,pair<int,int>>>> pq;
        vector<vector<int>> dis(n,vector<int>(m,INT_MAX));
        dis[0][0] = 0;
        pq.push({0, {0, 0}});
        while(!pq.empty()) {
            pair<int,pair<int,int>> t = pq.top(); pq.pop();
            int d = t.first, r = t.second.first, c = t.second.second;
            if(r==n-1 && c==m-1) return d;
            for(int i=0; i<4; ++i) {
                int x = r+xdir[i], y = c+ydir[i];
                if(x < 0 || x >= n || y < 0 || y >= m)continue;
                int dist = max(d, abs(heights[x][y] - heights[r][c]));
                if (dist < dis[x][y]) {
                    dis[x][y] = dist;
                    pq.push({dist, {x, y}});
                }
            }
        }
        return 0;
    }
};