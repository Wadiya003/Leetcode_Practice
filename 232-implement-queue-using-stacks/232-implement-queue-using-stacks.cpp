class MyQueue {
public:
    stack<int>s;
    MyQueue() {
        
    }
    
    void push(int x) {
         if(s.size()==0){
            s.push(x);
            return;
        }
        int data;
        data = s.top();
        s.pop();
        push(x);
        s.push(data);
        return;
    }
    
    int pop() {
        int temp =s.top();s.pop();
        return temp;
    }
    
    int peek() {
        return s.top();
    }
    
    bool empty() {
        if(!s.empty())return false;return true;
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */