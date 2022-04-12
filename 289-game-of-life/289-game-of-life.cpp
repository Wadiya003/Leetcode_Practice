class Solution {
public:
    void gameOfLife(vector<vector<int>>& board) {
    int rows = board.size(), cols = board[0].size();
    vector<vector<int>> ans(rows,vector<int>(cols,0));                            
    for(int r = 0; r < rows; r++){
        for(int c = 0; c < cols; c++){
    int cnt = count(board, r-1, c-1) + count(board, r-1, c) + count(board, r-1, c+1) + count(board, r, c+1) +count(board, r+1, c+1) + count(board, r+1, c) +count(board, r+1, c-1) + count(board, r, c-1);
             if(board[r][c] == 1){ 
                ans[r][c] = (cnt < 2 || cnt > 3) ? 0 : 1;      
            }else{ 
                ans[r][c] = (cnt == 3) ? 1 : 0;
            }
        }
    }
        board=ans;
    }
    int count(vector<vector<int>>& board,int r,int c){
if( r < 0 || r >= board.size() || c < 0 || c >= board[0].size() || board[r][c] == 0 ){ return 0; }                          // out of bound cases
    return 1; }
};