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
    // 二刷
    ListNode *detectCycle(ListNode *head) {
        if(!head || !head->next) return nullptr;
        ListNode *s=head;
        ListNode *f=head;
        while(f && f->next){
            s=s->next;
            f=f->next->next;
            if(s==f) break;
        }
        if(!f || !f->next) return nullptr;
        s=head;
        while(s!=f){
            s=s->next;
            f=f->next;
        }
        return f;
    }
    
    
    
    ListNode *detectCycle1(ListNode *head) {
        if(!head || !head->next) return nullptr;
        ListNode *s=head->next;  //之前调试了很久，因为写成了"ListNode *s=head;"。注意 s的步长 和 f的步长 之间是二倍关系！！！
        ListNode *f=head->next->next;
        int n=0;
        while(s!=f){
            if(s->val==2) n++;
            if(!f || !f->next || !f->next->next) return nullptr;
            s=s->next;
            f=f->next->next;
        }
        cout<<s->val<<" "<<n<<endl;
        s=head;
        while(s!=f){
            s=s->next;
            f=f->next;
        }
        return f;
    }
};