class Solution {
public: //observation based
    vector<int> pathInZigZagTree(int label) {
        vector<int>ans;
        int height=log2(label); //get the height of tree
        ans.push_back(label); //starting element
            while(height!=0){
                int left=pow(2,height-1); //get the leftmost
                int right=pow(2,height)-1; //get the rightmost
                label=left+right-label/2; //give the parent of label
                ans.insert(ans.begin(),label);
                height--;
              }
        return ans;
    }
};