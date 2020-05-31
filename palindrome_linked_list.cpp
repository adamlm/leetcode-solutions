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
    bool isPalindrome(ListNode* head) {
        auto fast{head};
        auto slow{head};
        
        while (fast != nullptr && fast->next != nullptr) {
            fast = fast->next->next;
            slow = slow->next;
        }
        
        if (fast != nullptr) {
            slow = slow->next;
        }
        
        slow = reverse(slow);
        
        while (slow != nullptr) {
            if (slow->val != head->val) {
                return false;
            }
            
            slow = slow->next;
            head = head->next;
        }
        
        return true;
    }
    
    ListNode* reverse(ListNode* head) {
        ListNode* prev = nullptr;
        ListNode* node = head;
        ListNode* next = nullptr;
        
        while (node != nullptr) {
            next = node->next;
            node->next = prev;
            prev = node;
            node = next;
        }
        
        return prev;
    }
};
