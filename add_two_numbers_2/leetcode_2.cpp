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
    ListNode* add(ListNode *l1, ListNode* l2, int carry){
        if(!l1 && !l2 && carry == 0) return NULL;
        int val1, val2;
        ListNode *next1, *next2;

        if(!l1){
            val1 = 0;
            next1 = NULL;
        }
        else{
            val1 = l1->val;
            next1 = l1->next;
        }
        if(!l2){
            val2 = 0;
            next2 = NULL;
        }
        else{
            val2 = l2->val;
            next2 = l2->next;
        }
        int sum = val1 + val2 + carry;
        int digit = sum % 10;
        carry = sum / 10;
        ListNode* digit_node = new ListNode(digit);
        digit_node->next = add(next1, next2, carry);
        return digit_node;
    }
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        return add(l1, l2, 0);
    }
};