// Given the head of a singly linked list, return true if it is a palindrome or false otherwise.


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
    ListNode* reverse(ListNode* head){
        ListNode* cur = head , *prev = nullptr, *next = nullptr;
        while(cur){
            next = cur->next;
            cur->next = prev;
            prev = cur;
            cur = next;
        }
        return prev;
    }
    bool isPalindrome(ListNode* head) {
        ListNode* fast = head , *slow = head;
        if(slow->next == NULL) return true;
        if(slow->next->next == NULL) {
            return (slow->val == slow->next->val)? true : false;
        }
        while(fast->next && fast->next->next){
            slow = slow ->next;
            fast = fast->next;
            fast = fast->next;
        }
        fast = slow->next;
        fast = reverse(fast);
        slow->next = fast;
        slow = head;
        while(slow && fast){
            if(slow->val != fast->val){
                return false;
            }
            slow = slow->next;
            fast = fast->next;
        }
        return true;
    }
};