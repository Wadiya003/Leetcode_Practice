class Solution {
public:
    int maximumUnits(vector<vector<int>>& boxTypes, int truckSize) {
        sort(boxTypes.begin(),boxTypes.end(), [](auto &a, auto &b)
             {return a[1] > b[1];});
        int ans=0;
        for(int i =0;i<boxTypes.size();i++){
            int box=min(boxTypes[i][0],truckSize);
            ans+=box*boxTypes[i][1];
            truckSize-=box;
            if(truckSize==0)
                break;
        }
           return ans;
        
    }
};