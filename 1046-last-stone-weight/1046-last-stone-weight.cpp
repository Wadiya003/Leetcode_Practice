class Solution {
public: //priority queue
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int>pq;
         for(auto a:stones){
          pq.push(a);
         }
    while(pq.size()>1){
    
      int f= pq.top();pq.pop();
      int s= pq.top();pq.pop();
        if(f!=s){
            pq.push(f-s);
        }
        
    }
        if(pq.size()==0)return 0;
        return pq.top();
    }
};