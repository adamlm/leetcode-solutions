class MyQueue {
private:
    stack<int> data;
    int front;
    
public:
    /** Initialize your data structure here. */
    MyQueue() {
        
    }
    
    /** Push element x to the back of queue. */
    void push(int x) {
        if (this->data.empty()) {
            this->front = x;
        }
        
        this->data.push(x);
    }
    
    /** Removes the element from in front of queue and returns that element. */
    int pop() {
        stack<int> tmp;
        
        const int iterations = this->data.size() - 1;
        for (auto i{0}; i < iterations; i++) {
            if (i == iterations - 1) {
                this->front = this->data.top();
            }
            
            tmp.push(this->data.top());
            this->data.pop();
        }
        
        const int ret = this->data.top();
        this->data.pop();
        
        for (auto i{0}; i < iterations; i++) {
            this->data.push(tmp.top());
            tmp.pop();
        }
        
        return ret;
    }
    
    /** Get the front element. */
    int peek() {
        return this->front;
    }
    
    /** Returns whether the queue is empty. */
    bool empty() {
        return this->data.empty();
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
