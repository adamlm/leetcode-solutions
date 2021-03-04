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
    ListNode* swapPairs(ListNode* head) {
        if (head == nullptr) {
            return head;
        }
        
        ListNode *ptr1{head};
        ListNode *ptr2{head->next};
        ListNode *ptr3{nullptr};
        
        while (ptr2 != nullptr) {
            ptr1->next = ptr2->next;
            ptr2->next = ptr1;
            
            if (ptr3 == nullptr) {
                head = ptr2;
            } else {
                ptr3->next = ptr2;
            }
            
            if (ptr1->next == nullptr) {
                break;
            }
            
            if (ptr3 == nullptr) {
                ptr3 = head->next;
            } else {
                ptr3 = ptr2->next;
            }
            
            ptr1 = ptr1->next;
            ptr2 = ptr1->next;
        }
        
        return head;
    }
};
