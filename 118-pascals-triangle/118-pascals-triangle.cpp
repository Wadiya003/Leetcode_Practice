class Solution {
public:
    vector<vector<int>> generate(int numRows) {
     vector<vector<int>> ret;//ans vector
	for (int i = 0; i < numRows; i++) { //increasing the size at each iteration
		vector<int> row(i + 1, 1); //initialising with 1 
		for (int j = 1; j < i; j++) { 
			row[j] = ret[i - 1][j] + ret[i - 1][j - 1]; //updating middle values
		}
		ret.push_back(row); //into our ans vector
	}
	return ret;   
    }
};