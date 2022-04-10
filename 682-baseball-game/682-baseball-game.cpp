class Solution {
public:
    int calPoints(vector<string>& ops) {
        stack<int>s;
        int ans=0; 
      
        for(int i =0;i < ops.size();i++){
            if( ops[i]=="C"){
                s.pop();
            }
            else if( ops[i]=="D"){
             int doi=s.top();
            s.push(2*doi);
            }
            else if( ops[i]=="+"){
              int tp=s.top();s.pop();
                int Sp=tp+s.top();
                s.push(tp);
                s.push(Sp);
            }
            else{
              s.push(stoi(ops[i]));}
          }
        while(!s.empty()){
        ans+=s.top();
        s.pop();}
        return ans;
    }
};