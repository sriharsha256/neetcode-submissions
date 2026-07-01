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
        ListNode* slow  = head;
        ListNode* fast = head;
        while(fast!=NULL && fast->next!=NULL)
        {
            slow = slow->next;
            fast = fast->next->next;
        }
        if(fast!=NULL)
        slow = slow->next;
        ListNode* pre = NULL;
        ListNode* curr = slow;
        ListNode* next = NULL;
        while(curr)
        {
            next = curr->next;
            curr->next = pre;
            pre = curr;
            curr = next;
        }
        ListNode* left = head;
        while(pre)
        {
            if(pre->val != left->val )
            return false;
            pre = pre->next;
            left = left->next;
        }
        return true;
        
    }
};