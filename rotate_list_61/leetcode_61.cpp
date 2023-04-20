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
    ListNode* rotateRight(ListNode* head, int k) {
        if(!head) return head;
        int length = 1;
        ListNode* temp = head;
        while(temp->next){
            length++;
            temp = temp->next;
        }
        if(length == 1) return head;
        k = k % length;
        if(k == 0) return head;
        ListNode* tail = temp;
        tail->next = head;

        k = length - k;
        while(k){
            tail = tail->next;
            k--;
        }
        ListNode* new_head = tail->next;
        tail->next = NULL;
        return new_head;

    }
};