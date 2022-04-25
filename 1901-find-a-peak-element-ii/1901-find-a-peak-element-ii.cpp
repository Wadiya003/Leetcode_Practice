class Solution {
public:// find global max in the mid column 
    vector<int> findPeakGrid(vector<vector<int>>& mat) {
        int row=mat.size();
        int col=mat[0].size();
        int start=0;
        int end=col-1;
        while(start<=end){
        int midcol=start + (end-start)/2;
        int maxrow=0;
        for(int i =0; i < row;i++){
            if(mat[i][midcol]>mat[maxrow][midcol]){
                maxrow=i;
            }
        }
        if((midcol==0||mat[maxrow][midcol]>mat[maxrow][midcol-1])&&(midcol==col-1||mat[maxrow]             [midcol]>mat[maxrow][midcol+1]))
        {
            return {maxrow,midcol};
        }
        else if(midcol>0 && mat[maxrow][midcol-1]>mat[maxrow][midcol])
        {
            end=midcol-1;
        }
        else
        {
            start=midcol+1;
        }
        }return {-1,-1};
    }
};
