class Solution {
public:
    vector<int> findRightInterval(vector<vector<int>>& intervals) {
        vector<int> ans(intervals.size());
        unordered_map<int, int> mp;
        for(int i = 0; i < intervals.size(); i++){
            mp[intervals[i][0]] = i;}
        sort(intervals.begin(),intervals.end());
        for(int i=0;i<intervals.size();i++){
          int j=i+1;
          int k=intervals.size()-1;
          if(intervals[i][0]==intervals[i][1])
            {
                ans[mp[intervals[i][0]]]=mp[intervals[i][0]];   
                continue;
            }

        while(j<=k){
              int m=j+(k-j)/2;
                if(intervals[m][0]>=intervals[i][1])
                {
                    k=m-1;
                }
                else
                {
                    j=m+1;
                }
          }
         if(j==intervals.size()){ans[mp[intervals[i][0]]]=-1;}
        else{ans[mp[intervals[i][0]]]=mp[intervals[j][0]];
            }
          
        }return ans;
    }
};