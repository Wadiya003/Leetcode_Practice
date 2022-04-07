class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        sort(stones.begin(),stones.end());
        while(stones.size()>1){
            int i=stones.size()-1;
            int first=stones[i],second=stones[i-1];
            stones.pop_back();
            stones.pop_back();
            if(first!=second)
            stones.push_back(first-second);
            sort(stones.begin(),stones.end());
        }
        if(stones.size()==0)
            return 0;
        return stones[0];
    }
};