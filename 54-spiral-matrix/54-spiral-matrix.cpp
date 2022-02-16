class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int row=matrix.size();
    int col=matrix[0].size();
        vector<int>v(row*col);
int rowstart=0;//to iterate form the starting of rows
int rowend=row-1; // to iterate from the last rows
int colstart=0; // to iterate from the starting of columns
int colend=col-1; // to iterate from the last columns
//helix matrix
int p=0;
while (rowstart<=rowend &&colstart<=colend){
    
for(int col=colstart;col<=colend;col++){
v[p++]=matrix[rowstart][col];
}if(++rowstart>rowend){break;}

for(int row=rowstart;row<=rowend;row++){
v[p++]=matrix[row][colend];
}if(--colend<colstart){break;}

for (int col=colend;col>=colstart;col--){
v[p++]=matrix[rowend][col];
}if(--rowend<rowstart){break;}


for(int row=rowend;row>=rowstart;row--){
v[p++]=matrix[row][colstart];
}if(colstart++ >colend){break;}
}return v;
    }
};