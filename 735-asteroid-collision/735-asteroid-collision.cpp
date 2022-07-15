class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroid) {
        vector<int>ans;
        stack<int>s;
        for(int i =0;i<asteroid.size();i++){
             if(asteroid[i] > 0 || s.empty()) {
                s.push(asteroid[i]);
            }
            else {
                while(!s.empty() and s.top() > 0 and s.top() < abs(asteroid[i])) {
                    s.pop();
                }
                if(!s.empty() and s.top() == abs(asteroid[i])) {
                    s.pop();
                }
                else {
                    if(s.empty() || s.top() < 0) {
                        s.push(asteroid[i]);
                    }
                }
            }
        }
        while(!s.empty()){
            ans.push_back(s.top());
            s.pop();
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};