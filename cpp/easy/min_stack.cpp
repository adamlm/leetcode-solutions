class MinStack {
private:
    class Node {
    public:
        int val;
        Node *next;
        Node(int x) {this->val = x; this->next = nullptr;};
    };
    Node *head;
public:
    /** initialize your data structure here. */
    MinStack() {
        this->head = nullptr;
    }
    
    void push(int x) {
        if (this->head == nullptr) {
            this->head = new Node(x);
        } else {
            auto tmp = this->head;
            this->head = new Node(x);
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
        auto node = this->head;
        auto min = INT_MAX;
        
        while (node != nullptr) {
            if (node->val < min) {
                min = node->val;
            }
            node = node->next;
        }
        
        return min;
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
