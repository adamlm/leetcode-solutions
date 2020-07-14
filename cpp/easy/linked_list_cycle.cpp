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
        unordered_set<ListNode *> set;
        auto node = head;
        
        while (node != nullptr) {
            set.insert(node);
            if (set.find(node->next) != set.end()) {
                return true;
            }
            node = node->next;
        }
        
        return false;
    }
};
