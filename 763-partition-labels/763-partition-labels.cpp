class Solution {
public:
    vector<int> partitionLabels(string s) {
        unordered_map<char,int>m;
        vector<int>ans;
        int j=0,k=0;
        for(int i=0;i<s.length();i++){
            m[s[i]]=i;//store last index of char
        }

        for(int i =0;i<s.length();i++){
            j=max(j,m[s[i]]); //extend the substr length 
            if(i==j){ //that means we take each char into account between i and now we can add this to ans 
                ans.push_back(i-k+1);
                k=i+1; //new starting point
            }
        }return ans;
        
    }
};