class Solution {
public:
    //round robbin shceduling type
    int leastInterval(vector<char>& tasks, int n) {
        unordered_map<int,int>fre;
        for(auto a : tasks){
         fre[a]++;
        }
        int ans=0;
        int m=tasks.size();
        priority_queue<int> q;
        for (const auto& f: fre) q.push(f.second);
        while(!q.empty()){
        int time=0;
        vector<int>tmp;
        for(int i=0;i<n+1;i++){
            if(!q.empty()){
                tmp.push_back(q.top());
                q.pop();
                time++;
            }
        }
            
        for(auto t:tmp){
            if(--t){
                q.push(t);
                
            }
        }   
            
            ans+=(!q.empty()?n+1:time);
        }
        return ans;
    
        
    }
};