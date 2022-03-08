class Solution {
public:
    vector<int> beautifulArray(int n) {
            if(n==1)
            return {1};
        vector<int>even = beautifulArray(n/2);
        vector<int>odd = beautifulArray(n-(n/2));
        vector<int>ans;
        for(auto e:even)
            ans.push_back(2*e);
        for(auto o:odd)
            ans.push_back((2*o)-1);
        return ans;
    }
    
};