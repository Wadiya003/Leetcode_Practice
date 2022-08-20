class Solution {
public:
    int minRefuelStops(int target, int startFuel, vector<vector<int>>& stations) {
       
        vector<long>dp(stations.size()+1,0);
        dp[0]=startFuel;//no station = can rech till start Fuel
        for(int i=0;i<stations.size();i++){//add stations
           for(int j=i;j>=0;--j){
               if(dp[j]>=stations[i][0]) //can reach next station
                   dp[j+1]=max(dp[j+1],dp[j]+ (long)stations[i][1]);
               //take mx distance we can reach
           }
        }
        for(int i=0;i<=stations.size();++i){
            if(dp[i]>=target){
                return i;
            }
        }
        return -1;
    }
};