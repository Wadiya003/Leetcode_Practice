class Solution {
public:
    int minCost(string colors, vector<int>& neededTime) {
        int ans=0;
        int i=0,j=0;
        while(i<neededTime.size() && j<neededTime.size()){
        int cur=0;
        int curMax=0;
            while(j<neededTime.size() && colors[i]==colors[j]){
                cur+=neededTime[j];
                curMax=max(curMax,neededTime[j]);
                j++;
            }
        ans+=cur-curMax;
        i=j;
        }
        return ans;
    }
};