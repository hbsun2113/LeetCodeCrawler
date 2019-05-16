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
    
    
    // 二刷，不难
    ListNode* rotateRight(ListNode* head, int k) {
        if(!head || k==0) return head;
        ListNode* newhead=new ListNode(INT_MIN);
        newhead->next=head;
        ListNode* f=head;
        ListNode* s=newhead;
        int len=0;
        while(f){
            len++;
            f=f->next;
            s=s->next;
        }
        k%=len;
        s->next=head;
        len-=k;
        f=head;
        s=newhead;
        while(--len>=0){
            f=f->next;
            s=s->next;
        }
        newhead->next=f;
        s->next=nullptr;
        return newhead->next;
        
        
        
        
    }
    
    
    //这个代码不必看，直接自己画图推导一下应该就能写出来。
    ListNode* rotateRight1(ListNode* head, int k) {
        if(!head) return head;
        ListNode *newhead=new ListNode(-100);
        newhead->next=head;
        ListNode *tail=newhead;
        ListNode *curr=head;
        int len=1;
        while(curr){
            len++;
            curr=curr->next;
            tail=tail->next;
        }
        len--;
        k=k%len;
        
        if(k==0) return head;
        
        tail->next=head;
        curr=newhead;
        int t=1;
        len-=k;
        while(t<=len){
            curr=curr->next;
            t++;
        }
        newhead=curr->next;
        curr->next=nullptr;
        return newhead;
    }
};