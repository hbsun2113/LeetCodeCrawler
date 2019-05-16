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
    ListNode* reverseBetween(ListNode* head, int m, int n) {
        ListNode* newhead=new ListNode(INT_MIN);
        newhead->next=head;
        ListNode* f=head;
        ListNode* s=newhead;
        int count=0;
        while(++count<m){
            f=f->next;
            s=s->next;
        }
        // cout<<s->val<<" "<<f->val<<endl;
        ListNode* save_f=f;
        ListNode* t1=f->next;
        while(++count<=n){
            ListNode* t2=t1->next;
            t1->next=f;
            f=t1;
            t1=t2;
        }
        save_f->next=t1;
        s->next=f;
        return newhead->next;
        
    }
};