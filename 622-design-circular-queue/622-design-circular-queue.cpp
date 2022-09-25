
struct Node {
public:
    int val;
    Node* next;
    Node(int v, Node* n=nullptr) {
        val = v;
        next = n;
    }
};
class MyCircularQueue {
private:   
    int ss,n= 0;
    Node *head = new Node(0), *tail = new Node(0);
public:
 
    MyCircularQueue(int k) {
        ss=k;
    }
    
    bool enQueue(int value) {
        if(isFull()){
            return false;
        }
        Node* newnode= new Node(value);
        if(isEmpty()){
        head=newnode;
        tail=newnode;
        n++;
        }
        else{
        tail->next=newnode;
        n++;
        tail=tail->next;
        }
        return true;
    }
    
    bool deQueue() {
        if(isEmpty()){
            return false;
        }
        Node* temp = head;
        head = head->next;
        delete temp;
        n--;
        return true;
    }
    
    int Front() {
         return isEmpty() ? -1 : head->val;
    }
    
    int Rear() {
         return isEmpty() ? -1 : tail->val;
    }
    
    bool isEmpty() {
        return n==0;
    }
    
    bool isFull() {
        return n==ss;
    }
};

/**
 * Your MyCircularQueue object will be instantiated and called as such:
 * MyCircularQueue* obj = new MyCircularQueue(k);
 * bool param_1 = obj->enQueue(value);
 * bool param_2 = obj->deQueue();
 * int param_3 = obj->Front();
 * int param_4 = obj->Rear();
 * bool param_5 = obj->isEmpty();
 * bool param_6 = obj->isFull();
 */