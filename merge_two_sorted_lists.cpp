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
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode* cur1 = l1;
        ListNode* cur2 = l2;
        ListNode* outHead;
        ListNode* outCur;
        
        if (l1 == NULL && l2 == NULL) {
            return outHead;
        } else if (l1 == NULL) {
            outHead = cur2;
            cur2 = cur2->next;
        } else if (l2 == NULL) {
            outHead = cur1;
            cur1 = cur1->next;
        } else {
            if(cur1->val < cur2->val) {
                outHead = cur1;
                cur1 = cur1->next;
                outCur = outHead;
                outCur->next = cur2;
            } else {
                outHead = cur2;
                cur2 = cur2->next;
                outCur = outHead;
                outCur->next = cur1;
            }
        }

        while(cur1 != NULL && cur2 != NULL) {
            if (cur1->val < cur2->val) {
                outCur->next = cur1;
                cur1 = cur1->next;
                outCur = outCur->next;
                outCur->next = cur2;
            } else {
                outCur->next = cur2;
                cur2 = cur2->next;
                outCur = outCur->next;
                outCur->next = cur1;
            }
        }
        
        return outHead;
    }
};
