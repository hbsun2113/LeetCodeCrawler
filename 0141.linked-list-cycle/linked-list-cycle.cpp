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
    bool hasCycle(ListNode *head) {
        if(!head || !head->next) return false;
        ListNode *f=head->next, *s=head;
        while(f!=s){
            if(s) s=s->next;
            if(f && f->next) f=f->next->next;
            else return false;
        }
        return true;
    }
};