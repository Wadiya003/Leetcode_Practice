class Solution {
public:  
   int helper(vector<int> piles, int m, int idx, bool aliceTurn, vector<vector<vector<int>>>& dp) {
        
        if(idx >= piles.size()) return 0;
        
        if(dp[idx][m][aliceTurn] != -1) return dp[idx][m][aliceTurn];
        
        if(aliceTurn) {     // When its Alice's turn she will try to maximize her count of stones. 
            int ans = 0, sum = 0;   
            for(int i=idx; (i-idx) < 2*m && i < piles.size(); i++) {
                sum += piles[i];
                ans = max(ans, sum + helper(piles, max((i-idx)+1, m), i+1, !aliceTurn, dp));
            }
            dp[idx][m][aliceTurn] = ans;
        } 
        else {        // When its Bob's turn he just makes sure Alice gets the minimum possible stones.
            int ans = INT_MAX;
            for(int i=idx;(i-idx) < 2*m && i < piles.size(); i++) {
                ans = min(ans, helper(piles, max((i-idx)+1, m), i+1, !aliceTurn, dp)); 
            }
            dp[idx][m][aliceTurn] = ans;
        }
        
        return dp[idx][m][aliceTurn];
    }
    
    
    
    int stoneGameII(vector<int>& piles) {
        int sz = piles.size();
        //to store idx , m , alice's turn ;
        vector<vector<vector<int>>> dp(sz, vector<vector<int>>(2*sz, vector<int>(2, -1)));
        return helper(piles, 1, 0, true, dp);}
};