class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int, int> m1;
        vector<int> re;
        if(nums1.size()<nums2.size()){
            return intersection(nums2,nums1);
        }
        else{
        for(auto num:nums1){
            m1[num]++;
        }
            for(auto it:nums2){
              if(m1.find(it) != m1.end() && m1[it] != -1){
            re.push_back(it);
            m1[it] = -1;
        }}
            
        }
        return re;
    }
};