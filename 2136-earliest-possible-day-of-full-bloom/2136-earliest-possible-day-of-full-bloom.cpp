class Solution {
public:
    int earliestFullBloom(vector<int>& plantTime, vector<int>& growTime) {
        int ans=0;
        int cur=0;
        int n=plantTime.size();
        vector<pair<int,int>>v(n);
        for(int i=0;i<n;i++){
        v[i].second=plantTime[i];
        v[i].first=growTime[i];
        }
        sort(rbegin(v),rend(v));
        for(int i=0;i<n;i++){
          ans=max(ans,cur+v[i].second+v[i].first);
         cur+=v[i].second;
       }
        return ans;
    }
};