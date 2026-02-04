// Given the heads of two singly linked-lists headA and headB, return the node at which the two lists intersect. If the two linked lists have no intersection at all, return null.

// For example, the following two linked lists begin to intersect at node c1


/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
    int getlen(ListNode* head){
        int count = 0;
        while(head){
            count++;
            head = head->next;
        }
        return count;
    }
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        int c1,c2,lead;
        c1 = getlen(headA);
        c2 = getlen(headB);
        if(c1 > c2 ){
            while(c1>c2){
                headA = headA->next;
                c1--;
            }
        }
        if(c2>c1){
            while(c2>c1){
                headB=headB->next;
                c2--;
            }
        }
        while(headA && headB ){
            if(headA == headB) return headA;
            headA=headA->next;
            headB=headB->next;
        }
        return nullptr;
    }
};