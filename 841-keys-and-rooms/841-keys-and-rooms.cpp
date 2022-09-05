class Solution {
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        queue<int>q;
        int n=rooms.size();
        vector<bool>vis(n,0);
        q.push(0);
        vis[0]=1;
       // int cnt=0;
        while(!q.empty()){
            for (int key : rooms[q.front()]) {
                if (!vis[key]) {
                    q.push(key);
                    vis[key]=1;
                    //cnt++;
                }
            }
            q.pop();
        }
        for(int i=0;i<rooms.size();i++){
            if(vis[i] == 0) return false;
        }
        return true;
    }
};