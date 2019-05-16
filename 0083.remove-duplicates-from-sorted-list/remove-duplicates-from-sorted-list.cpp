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
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode* result=head;
        ListNode *s=head,*f=head;
        while(s){
            f=s->next;
            while(f && f->val==s->val)
                f=f->next;
            s->next=f;
            s=s->next;
        }
        return result;
    }
};