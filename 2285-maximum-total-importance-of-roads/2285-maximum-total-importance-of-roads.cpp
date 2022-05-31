class Solution {
public:
    long long maximumImportance(int n, vector<vector<int>>& roads) {
        vector<int> m(n,0);
        int cnt=1;
        //Suppose node with higher value is n ,its value is v and its degree is d . Then this node will be present a total of d times in the ans , so total contribution of n to ans is d*v. Here i+1 is v and A[i] is d after sorting.

        for (const vector<int>& edge : roads) {
            m[edge[0]]++;
            m[edge[1]]++;
        }
        sort(m.begin(),m.end());
     
        long long sum=0;
         for (auto a : m){
            sum+=((long long)a*cnt);
             cnt++;
         }
        return sum;
    }
    
};