class Solution {
public:
    int MOD = 1e9 + 7;
    int bit(int i){
        return log2(i) + 1;
    }
    int concatenatedBinary(int n) {
        long ans = 0;
        for (int i = 1; i <= n; ++i) {
            int len = bit(i);
            ans = ((ans << len) % MOD + i) % MOD;
        }
        return int(ans);
    }
};