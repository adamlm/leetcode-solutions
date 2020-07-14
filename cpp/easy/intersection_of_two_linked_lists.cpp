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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        unordered_set<ListNode *> set;
        
        while (headA != nullptr || headB != nullptr) {
            if (headA != nullptr) {
                if (set.find(headA) == set.end()) {
                    set.insert(headA);
                } else {
                    return headA;
                }
                
                headA = headA->next;
            }
            
            if (headB != nullptr) {
                if (set.find(headB) == set.end()) {
                    set.insert(headB);
                } else {
                    return headB;
                }

                headB = headB->next;   
            }
        }
        
        return nullptr;
    }
};
