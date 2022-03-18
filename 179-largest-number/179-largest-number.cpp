class Solution {
public:
    string largestNumber(vector<int>& nums) {
        string s="";
         sort(nums.begin(),nums.end(),[](const int &m,const int&n){
                    return to_string(m)+to_string(n)>to_string(n)+to_string(m);});
        for(int i=0;i<nums.size();i++){
        s+=to_string(nums[i]);
        }
        if(s[0]=='0')
        {return "0";}
       return s;
    }
};