class MyCalendarThree {
public:
    map<int,int>m;
    
    MyCalendarThree() {
        
    }
    
    int book(int start, int end) {
        int cur=0;
        int ans=0;
        m[start]++;
        m[end]--;
        for(auto mm:m){
            cur+=mm.second;
            ans=max(ans,cur);
        }
        return ans;
    }
};

/**
 * Your MyCalendarThree object will be instantiated and called as such:
 * MyCalendarThree* obj = new MyCalendarThree();
 * int param_1 = obj->book(start,end);
 */