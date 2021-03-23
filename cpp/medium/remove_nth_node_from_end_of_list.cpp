/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        vector<ListNode *> ptrs;
        
        for (auto h = head; h != nullptr;) {
            ptrs.push_back(h);
            h = h->next;
        }
        
        if (ptrs.size() < n) {
            head = nullptr;
        } else if (ptrs.size() == n) {
            head = head->next;
        } else {
            auto prev = ptrs[ptrs.size() - n - 1];
            auto cur = ptrs[ptrs.size() - n];
            prev->next = cur->next;
            cur->next = nullptr;
        }
        
        return head;
    }
};
