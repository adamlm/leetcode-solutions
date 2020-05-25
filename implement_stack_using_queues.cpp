class MyStack {
private:
    queue<int> data;
    
public:
    /** Initialize your data structure here. */
    MyStack() {
        
    }
    
    /** Push element x onto stack. */
    void push(int x) {    
        this->data.push(x);
    }
    
    /** Removes the element on top of the stack and returns that element. */
    int pop() {
        queue<int> tmp;
        
        const int iterations = this->data.size() - 1;
        for (auto i{0}; i < iterations; i++) {
            tmp.emplace(this->data.front());
            this->data.pop();
        }

        const int retVal = this->data.front();
        this->data.pop();
        this->data.swap(tmp);
        
        return retVal;
    }
    
    /** Get the top element. */
    int top() {
        return this->data.back();
    }
    
    /** Returns whether the stack is empty. */
    bool empty() {
        return this->data.empty();
    }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */
