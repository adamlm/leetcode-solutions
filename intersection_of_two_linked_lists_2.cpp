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
        auto nodeA{headA};
        auto nodeB{headB};
        ListNode* last = nullptr;
        
        while (headA != nullptr && headB != nullptr) {            
            if (nodeA == nodeB) {
                return nodeA;
            }
            
            if (nodeA->next == nullptr) {
                if (last == nullptr) {
                    last = nodeA;
                } else if (nodeA != last) {
                    return nullptr;
                }
                nodeA = headB;
            } else {
                nodeA = nodeA->next;                
            }
            
            if (nodeB->next == nullptr) {
                if (last == nullptr) {
                    last = nodeB;
                } else if (nodeB != last) {
                    return nullptr;
                }
                nodeB = headA;
            } else {
                nodeB = nodeB->next;
            }
        }
        
        return nullptr;
    }
};
