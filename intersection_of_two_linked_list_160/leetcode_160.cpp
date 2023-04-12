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
        if(!headA || !headB) return NULL;
        int countA = 0;
        int countB = 0;
        ListNode *dummyA = headA;
        ListNode *dummyB = headB;

        while(dummyA != NULL){
            dummyA = dummyA->next;
            countA++;
        }

        while(dummyB != NULL){
            dummyB = dummyB->next;
            countB++;
        }

        while(countA > countB){
            headA = headA->next;
            countA--;
        }

        while(countB > countA){
            headB = headB->next;
            countB--;
        }

        while(headA){
            cout << headA->val << " " << headB->val << endl;
            if(headA == headB) return headA;
            headA = headA->next;
            headB = headB->next;
        }
        return NULL;
    }
};