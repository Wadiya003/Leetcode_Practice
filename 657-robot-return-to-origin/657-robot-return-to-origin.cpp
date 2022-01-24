class Solution {
public:
    bool judgeCircle(string moves) {
        int count1=0;
        int count2=0;
        for(int i=0;i<moves.length();i++){
            if(moves[i]=='U')count1++;
            if(moves[i]=='D')count1--;
            if(moves[i]=='R')count2++;
            if(moves[i]=='L')count2--;
        }
        return count1==0 && count2==0;
    }
};