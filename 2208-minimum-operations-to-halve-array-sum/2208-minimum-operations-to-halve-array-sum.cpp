class Solution {
public:
    int halveArray(vector<int>& nums) {
        int ans=0;
        double sum = accumulate(nums.begin(), nums.end(), 0.00);
        double half = sum / 2;
        priority_queue<double> pq;
        for(auto& num : nums) pq.push((double)num);
        while(pq.size() && sum > half) {
            double tmp = pq.top(); pq.pop();
             tmp /= 2.00;
            sum -= tmp;
            ans++;
            if(tmp>0) pq.push(tmp);
        }
        return ans;
    }
};