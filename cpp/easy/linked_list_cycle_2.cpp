/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    bool hasCycle(ListNode *head) {
        if (head == nullptr) {
            return false;
        }
        
        auto slow = head;
        auto fast = head->next;
        
        while (fast != slow) {
            if (fast == nullptr || slow == nullptr || fast->next == nullptr) {
                return false;
            }
            
            slow = slow->next;
            fast = fast->next->next;
        }
        
        return true;
    }
};
