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
    void reorderList(ListNode* head) {
        if(!head || !head->next) return ;
        int len=0;
        ListNode* curr=head;
        while(curr){
            len++;
            curr=curr->next;
        }
        curr=head;
        int t=1;
        if(len%2==1) len++;
        while(t<len/2){
            t++;
            curr=curr->next;
        }
        ListNode *sec=reverse(curr->next);
        cout<<"sec="<<sec->val<<endl;
        
        ListNode *fir=head;
        while(fir && sec){
            ListNode *fir_next=fir->next;
            ListNode *sec_next=sec->next;
            fir->next=sec;
            sec->next=fir_next;
            fir=fir_next;
            sec=sec_next;
        }
        if(fir) fir->next=nullptr;
        if(sec) sec->next=nullptr;
        return;
    }
    
    ListNode* reverse(ListNode * head){
        if(!head) return head;
        ListNode *pre=nullptr;
        ListNode *curr=head;
        while(curr){
            ListNode *nnext=curr->next;
            curr->next=pre;
            pre=curr;
            curr=nnext;
        }
        return pre;
    }
};