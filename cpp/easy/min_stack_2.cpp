class MinStack {
private:
    class Node {
    public:
        int val;
        int min;
        Node *next;
        Node(int val, int min) {this->val = val; this->min = min, this->next = nullptr;};
    };
    Node *head;
public:
    /** initialize your data structure here. */
    MinStack() {
        this->head = nullptr;
    }
    
    void push(int x) {
        if (this->head == nullptr) {
            this->head = new Node(x, x);
        } else {
            auto tmp = this->head;
            this->head = new Node(x, min(x, tmp->min));
            this->head->next = tmp;
        }
    }
    
    void pop() {
        auto tmp = this->head->next;
        delete(this->head);
        this->head = tmp;
    }
    
    int top() {
        return this->head->val;
    }
    
    int getMin() {
        return this->head->min;
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(x);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */
