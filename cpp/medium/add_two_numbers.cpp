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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        auto head = l1;
        ListNode *tail;
        auto carry{0};
        
        if (l1->val == 0 && l1->next == NULL) {
            return l2;
        } else if (l2->val == 0 && l2->next == NULL) {
            return l1;
        }
        
        while (l1 != NULL && l2 != NULL) {
            l1->val = l1->val + l2->val + carry;
            carry = l1->val / 10;
            l1->val %= 10;
            
            tail = l1;
            l1 = l1->next;
            l2 = l2->next;
        }
        
        if(l2 != NULL) {
            tail->next = l2;
            l1 = tail->next;
        }
        
        while (l1 != NULL && carry > 0) {
            l1->val += carry;
            carry = l1->val / 10;
            l1->val %= 10;
            
            tail = l1;
            l1 = l1->next;
        }
        
        if (carry > 0) {
            tail->next = new ListNode(carry);
        }
        
        return head;
    }
};
