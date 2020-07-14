class NumArray {
private:
    vector<int> nums;
    
public:
    NumArray(vector<int>& nums) {
        this->nums = nums;
    }
    
    int sumRange(int i, int j) {
        if (i < 0 || j > this->nums.size() - 1) {
            return 0;
        }
        
        return accumulate(this->nums.begin() + i, this->nums.begin() + j + 1, 0, plus<int>());
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * int param_1 = obj->sumRange(i,j);
 */
