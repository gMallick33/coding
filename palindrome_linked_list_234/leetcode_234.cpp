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
    bool isPalindrome(ListNode* head) {
        if(!head) return true;
        ListNode* dummy = head;
        stack<int> mystack;
        while(dummy){
            mystack.push(dummy->val);
            dummy = dummy->next;
        }
        dummy = head;
        while(dummy){
            if(dummy->val == mystack.top()){
                mystack.pop();
                dummy = dummy->next;
            }
            else return false;
        }
        return true;
    }
};