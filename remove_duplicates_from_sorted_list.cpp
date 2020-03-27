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
    ListNode* deleteDuplicates(ListNode* head) {
        if (head == NULL) {
            return head;
        }
        
        auto slow{head};
        auto fast{head->next};
        
        while (fast != NULL) {
            if (fast->val != slow->val) {
                slow->next = fast;
                slow = slow->next;
            }
            
            fast = fast->next;
        }
        
        slow->next = NULL;
        
        return head;
    }
};
