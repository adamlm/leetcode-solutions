class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        int cash[3] = {0, 0, 0};
        
        for (auto bill: bills) {
            auto change{bill - 5};
            
            switch(bill) {
                case 5:
                    cash[0]++;
                    break;
                case 10:
                    cash[1]++;
                    break;
                case 20:
                    cash[2]++;
                    break;
            }
            
            switch(change) {
                case 15:
                    if (cash[1] > 0) {
                        cash[1]--;
                        change -= 10;
                    }
                case 5:
                    if (cash[0] >= change / 5) {
                        cash[0] -= change / 5;
                    } else {
                        return false;
                    }
            }
        }
        
        return true;
    }
};
