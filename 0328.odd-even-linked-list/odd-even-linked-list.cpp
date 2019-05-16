/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* oddEvenList(ListNode* head) {
        ListNode* newhead=new ListNode(INT_MAX);
        newhead->next=head;
        if(!head || !head->next || !head->next->next) return head;
        ListNode* one=head;
        ListNode* two=head->next;
        ListNode* thr=head->next->next;
        ListNode* oddhead=head;
        ListNode* evenhead=head->next;
        while(one && two && thr){
            one->next=thr;
            two->next=thr->next;
            one=one->next;
            if(one && one->next) two=one->next;
            else two=nullptr;
            if(two && two->next) thr=two->next;
            else thr=nullptr;
        }
        one->next=evenhead;
        
        
        return newhead->next;
    }
};