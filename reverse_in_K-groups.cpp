// Given the head of a linked list, reverse the nodes of the list k at a time, and return the modified list.

// k is a positive integer and is less than or equal to the length of the linked list. If the number of nodes is not a multiple of k then left-out nodes, in the end, should remain as it is.

// You may not alter the values in the list's nodes, only nodes themselves may be changed.

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
    int len(ListNode* head){
        int count=0;
        while(head!=NULL){
            count++;
            head=head->next;
            
        }
        return count;
    }
    ListNode* reverseKGroup(ListNode* head, int k) {
        if(head==NULL){
            return NULL;
        }
        if(len(head)<k)
            return head;
        ListNode* cur,*prev,*nex=head;
        prev=NULL;
        cur=head;
        int temp=k;
        while(temp>0&&nex!=NULL){
            nex=cur->next;
            cur->next=prev;
            prev=cur;
            cur=nex; 
            temp--;
        }
        if(nex!=NULL)
        head->next=reverseKGroup(nex,k);
        return prev;
    }
};