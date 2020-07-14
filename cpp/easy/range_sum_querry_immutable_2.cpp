class NumArray {
private:
    vector<int> sum{0};
    
public:
    NumArray(vector<int>& nums) {
        for (auto i{0}; i < nums.size(); i++) {
            this->sum.push_back(this->sum[i] + nums[i]);
        }
    }
    
    int sumRange(int i, int j) {
        return this->sum[j + 1] - this->sum[i];
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * int param_1 = obj->sumRange(i,j);
 */
