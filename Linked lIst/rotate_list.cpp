// Given the head of a linked list, rotate the list to the right by k places.

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
    int len(ListNode* head) {
        int n = 0;
        while(head) {
            head = head->next;
            n++;
        }
        return n;
    }
    
    ListNode* rotateRight(ListNode* head, int k) {
        if(!head || !head->next || k == 0) return head;
        int n = len(head);
        k = k % n;
        if(k == 0) return head;
        ListNode* temp = head;
        for(int i = 1; i < n - k; i++) {
            temp = temp->next;
        }
        ListNode* newHead = temp->next;  
        temp->next = nullptr;           
        ListNode* tail = newHead;
        while(tail->next) {
            tail = tail->next;
        }
        tail->next = head;
        return newHead;
    }
};