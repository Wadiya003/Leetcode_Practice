class Solution {
public:
    int bagOfTokensScore(vector<int>& tokens, int power) {
      sort(tokens.begin(),tokens.end());
      int score=0,ans=0;
      int l=0;
      int r=tokens.size()-1;
      while(l<=r){
          if(power>=tokens[l]){
              score++;
              power-=tokens[l];
              l++;
              ans=max(ans,score);
          }
          else if(score && tokens[l]>power){
              score--;
              power+=tokens[r];
              r--;
          }
          else{
              return ans;
          }
      }
        return ans;
    }
};
// maximize score not power
// greedy -> sort it acc to power , if power is greater than token -> use face-up 