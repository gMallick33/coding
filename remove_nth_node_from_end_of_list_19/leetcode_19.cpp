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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* start = new ListNode();
        start->next = head;
        ListNode *early = start;
        ListNode *late = start;
        
        while(n != 0){
            early = early->next;
            n--;
        }
        ListNode *prev = NULL;
        
        while(early != NULL){
            early = early->next;
            prev = late;
            late = late->next;
        }
        prev->next = late->next;
        return start->next;
        
    }
};