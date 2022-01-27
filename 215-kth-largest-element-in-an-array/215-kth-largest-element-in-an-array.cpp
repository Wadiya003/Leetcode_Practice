class Solution {
public: //minheap : Apply minheap to k elements and keeps on replacing th etop elements with the latter elements
    int findKthLargest(vector<int>& nums, int k) {
       priority_queue<int, vector<int>, greater<int>>Q;
        for(int i: nums){
            if(Q.size() <k)
                Q.push(i);
            else if(Q.top()<i){
                Q.pop();
                Q.push(i);
            }
        }
        return Q.top();   
    }
};