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
    ListNode* removeElements(ListNode* head, int val) {
        ListNode* res=new ListNode(INT_MAX);
        res->next=head;
        auto cur=res;
        while(cur){
            auto n=cur->next;
            while(n && n->val==val) n=n->next;
            cur->next=n;
            cur=cur->next;
        }
        return res->next;
    }
};