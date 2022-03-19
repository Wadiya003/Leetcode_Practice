class FreqStack {
public:
     int maxfreq ;
    unordered_map<int, int> freq; 
    unordered_map<int, stack<int>> freqsame; 
    
    FreqStack() {
        maxfreq=0;
    }
    
    void push(int val) {
        freq[val]++;
        if(freq[val]>maxfreq){
        maxfreq=freq[val];
        }
        freqsame[freq[val]].push(val); //with same freq 
    }
    
    int pop() {
       int top=freqsame[maxfreq].top();
        freqsame[maxfreq].pop();
        freq[top]--;
        if(freqsame[maxfreq].empty()){
        freqsame.erase(maxfreq);
        maxfreq--;}
       return top;
    }
};

/**
 * Your FreqStack object will be instantiated and called as such:
 * FreqStack* obj = new FreqStack();
 * obj->push(val);
 * int param_2 = obj->pop();
 */
