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
    //使用newhead的目的是为了处理删除头结点的情况：
    // [1,2] 2
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* newhead=new ListNode(-100);
        newhead->next=head;
        ListNode *s=newhead;
        ListNode *f=head;
        int t=1;
        while(t<=n){
            f=f->next;
            t++;
        }//使得快慢指针之间相差n+1步。
        while(f){
            f=f->next;
            s=s->next;
        }
        s->next=s->next->next;
        return newhead->next;
    }
    
    
    
    
    
    //很暴力求解，直接画图做的，根本没有什么思考
    ListNode* removeNthFromEnd1(ListNode* head, int n) {
        ListNode* cur=head;
        int len=1;
        while(cur){
            len++;
            cur=cur->next;
        }
        len--;
        if(len==n) return head->next;
        int tmp=1;
        cur=head;
        len-=n;
        while(tmp<len){
            tmp++;
            cur=cur->next;
        }
        if(cur->next) cur->next=cur->next->next;
        else cur->next=nullptr;
        return head;
        
    }
};