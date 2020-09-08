class MyHashMap {
private:
    vector<int> table;
    
public:
    /** Initialize your data structure here. */
    MyHashMap() {
    }
    
    /** value will always be non-negative. */
    void put(int key, int value) {
        if (key >= this->table.size()) {
            const auto size{static_cast<int>(this->table.size())};
            for (auto i{0}; i < key - size + 1; i++) {
                this->table.push_back(-1);
            }
        }
        
        this->table[key] = value;
    }
    
    /** Returns the value to which the specified key is mapped, or -1 if this map contains no mapping for the key */
    int get(int key) {
        if (key < this->table.size() && this->table[key] > -1) {
            return this->table[key];
        }
        
        return -1;
    }
    
    /** Removes the mapping of the specified value key if this map contains a mapping for the key */
    void remove(int key) {
        if (key < this->table.size()) {
            this->table[key] = -1;
        }
    }
};

/**
 * Your MyHashMap object will be instantiated and called as such:
 * MyHashMap* obj = new MyHashMap();
 * obj->put(key,value);
 * int param_2 = obj->get(key);
 * obj->remove(key);
 */
