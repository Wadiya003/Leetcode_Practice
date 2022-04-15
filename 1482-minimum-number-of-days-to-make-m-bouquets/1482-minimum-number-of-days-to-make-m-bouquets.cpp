class Solution {
public:
    bool cando(vector<int>& bloomDay, int m, int k,int days){
    int flowers = 0;
    for (auto b :bloomDay) {
        flowers = b <= days ? flowers + 1 : 0;
        if (flowers == k) {
           flowers= 0;
            --m;
        }
    }
    return m <= 0;
     }
    int minDays(vector<int>& bloomDay, int m, int k) {
        int ans=-1;
        int l=1;
        int r=1000000000;
         if (m * k > bloomDay.size())
        return -1;
        while(l<=r){
        int days=l+(r-l)/2;
            if(cando(bloomDay,m,k,days)){
                ans=days;
                r=days-1;
           }else{
                l=days+1;
            }
        }return ans;
    }
};