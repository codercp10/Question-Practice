// You are given the heads of two sorted linked lists list1 and list2.

// Merge the two lists into one sorted list. The list should be made by splicing together the nodes of the first two lists.

// Return the head of the merged linked list.


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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        if(list1 == nullptr && list2 != nullptr) return list2;
        if(list2 == nullptr && list1 != nullptr) return list1;
        if(list1==nullptr && list2 == nullptr) return nullptr;
        ListNode* head;
        if(list1->val<=list2->val) {
            head = list1; 
            list1=list1->next;
        } 
        else {
            head = list2;
            list2=list2->next;
        }
        ListNode* temp = head;
        
        while(list1 || list2){
            if(!list1){
                temp->next = list2;
                break;
            }
            if(!list2){
                temp->next = list1;
                break;
            }
            if(list1->val<=list2->val){
                temp->next = list1;
                temp = temp->next;
                list1=list1->next;
            }
            else if(list1->val>list2->val){
                temp->next = list2;
                temp = temp->next;
                list2=list2->next;
            }
        }
        return head;
    }
};