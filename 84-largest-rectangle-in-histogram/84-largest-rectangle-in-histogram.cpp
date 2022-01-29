class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int maxArea = 0; int i =0;
    stack<int> st;
       heights.push_back(0);
     while(i< heights.size()){
      if ( st.empty() || heights[i] > heights[st.top()]){
          
         st.push(i++);
      } else{int k =st.top();
                st.pop();
                int currArea = heights[k]*(st.empty()?i:i-st.top()-1);
                maxArea = max(maxArea,currArea);
            }
        }
 return maxArea;
    }
};