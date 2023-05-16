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
    ListNode* reverse(ListNode* head, int k){
        
        ListNode* cursor = head;
        for(int i = 0; i < k; i++){
            if(cursor == NULL) return head;
            cursor = cursor->next;
        }

        ListNode* curr = head;
        ListNode* next = NULL;
        ListNode* prev = NULL;
        int dup_k = k;
        while(dup_k > 0 && curr != NULL){
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
            dup_k--;
        }
        
        head->next = reverse(curr, k);
        return prev;
    }
    ListNode* swapPairs(ListNode* head) {
        if(head == NULL) return head;
        return reverse(head, 2);
    }
};