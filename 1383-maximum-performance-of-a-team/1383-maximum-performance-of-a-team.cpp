class Solution {
public:
    int maxPerformance(int n, vector<int>& speed, vector<int>& efficiency, int k) {
    vector<pair<int, int>>temp;
    long long int ans = 0;
    priority_queue<int, vector<int>, greater<int>> pq;
    long long int sum = 0;
    for (int i = 0; i < n; i++)
    {
    temp.push_back({efficiency[i], speed[i]});
    }
    sort(temp.rbegin(), temp.rend());
        
    for (int i = 0; i < n; i++)
    {
    sum += temp[i].second;
    pq.push(temp[i].second);

    if (pq.size() > k)
    {
        sum -= pq.top();
        pq.pop();
    }
    ans = max(ans, sum * temp[i].first);
    }
    return ans % 1000000007;
    }
};