class Solution {
public:
    int mod=1000000007;
    int helper(int xx, vector<int> &x) {
        sort(x.begin(), x.end()); 
        int n = x.size();
        int m = max(xx-x[n-1], x[0]);
        for (int i=1; i<n; i++) {
            m= max(m, x[i]-x[i-1]);
        }
        return m;
    }
    int maxArea(int h, int w, vector<int>& horizontalCuts, vector<int>& verticalCuts)     {  
        return (int)((long)helper(h, horizontalCuts)*helper(w,verticalCuts)%mod);
       
    }
};