class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        int n=board.size();//col
        int m=board[0].size();//row
        vector<set<int>>row(9);  vector<set<int>>col(9);
        vector<set<int>>block(9);
        int count=0;
        for(int i =0;i<m;i++){
         for(int j=0;j<n;j++){
           if(board[i][j]!='.'){
             int temp=board[i][j];
              if(row[i].count(temp) || col[j].count(temp) ||
                  block[(i/3)*3 + j/3].count(temp)){
                    return false;
                }
               row[i].insert(temp);
               col[j].insert(temp);
               block[(i/3*3) + j/3].insert(temp);//tricky part to map col {0,1,2,3,4,5,6,7,8}->{0,1,2} and row to{0,3,6}
        }
      }
    }
     return true;
    }
};