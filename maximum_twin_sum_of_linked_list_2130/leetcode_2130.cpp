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
    int pairSum(ListNode* head) {
        ListNode* dummy = head;
        stack<int> myStack;
        int countNodes = 0;
        while(dummy){
            myStack.push(dummy->val);
            dummy = dummy->next;
            countNodes++;
        }
        int maxi = 0;
        int half = countNodes / 2;
        while(half--){
            maxi = max(maxi, myStack.top() + head->val);
            myStack.pop();
            head = head->next;
        }
        return maxi;
    }
};