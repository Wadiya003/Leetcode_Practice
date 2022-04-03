class Solution {
public:
    int getmin(string &s){
     return stoi(s.substr(0,2))*60+stoi(s.substr(3));
    }
    int convertTime(string current, string correct) {
      int cnt=0;
      int diff=getmin(correct)-getmin(current);
      vector<int>take={60,15,5,1};
        for(auto min:take){
          cnt+=diff/min;
          diff%=min;}
        return cnt;
    }
};