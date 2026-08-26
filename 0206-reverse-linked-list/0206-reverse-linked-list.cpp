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
    ListNode* reverseList(ListNode* head) {
        ListNode* t=nullptr;
        ListNode* rh=nullptr;
        while(head !=nullptr){
            t=head;
            head=head->next;
            t->next=rh;
            rh=t;
        }
        return rh;
    }
};