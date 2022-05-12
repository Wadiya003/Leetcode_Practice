class Solution {
public:
    string largestGoodInteger(string num) {
        string ans;
        for(int i=0;i<num.length()-2;i++){
            if(num[i]==num[i+1] && num[i+1]==num[i+2]){
                string make="";
                make+=num[i];
                make+=num[i+1];
                make+=num[i+2];
                ans=max(ans,make);
            }
        }
        return ans;
    }
};
