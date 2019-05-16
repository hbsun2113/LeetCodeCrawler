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
    /*
        如果是[1,2,2,1],则f指向2。反转+断链后：
        [1,2]、[2,1]
        
        如果是[1,2,1],则f指向2。反转+断链后：
        [1,2] [1]
        
        因此只需要判断s和f都有效时是否相等即可，如果有一个为空了，直接返回true就行。
        因为我们是尽量均分链表，如果没有均分说明就是奇数个。
    */
    bool isPalindrome(ListNode* head) {
        if(!head || !head->next) return true;
        ListNode* newhead=new ListNode(INT_MIN);
        newhead->next=head;
        ListNode *f=newhead, *s=newhead;
        while(s && s->next){
            f=f->next;
            s=s->next->next;
        }

        cout<<"f:"<<f->val<<endl;
        s=revert(f->next);
        f->next=nullptr;
        f=head;
        
        while(s && f){
            if(s->val!=f->val) return false;
            // cout<<s->val<<" "<<f->val<<endl;
            s=s->next;
            f=f->next;
        }
        return true;
    }
    
    
    ListNode* revert(ListNode* head){
        if(!head || !head->next) return head;
        ListNode* nn=head->next;
        ListNode* res=revert(nn);
        nn->next=head;
        head->next=nullptr;
        return res;
    }
    
    
    
    
    bool isPalindrome1(ListNode* head) {
        if(!(head&&head->next)) return true;
        ListNode* s=head;
        ListNode* f=head->next;//得到中间节点
        while(f->next && f->next->next){
            s=s->next;
            f=f->next->next;
        }
        
        //cout<<s->val<<" "<<f->val<<endl;
        
        ListNode* tail=reverse(s);//后半部分的链表进行反转
        
        // ListNode* tmp=tail;
        // while(tmp){
        //     cout<<tmp->val<<endl;
        //     tmp=tmp->next;
        // }
        
        while(head && tail){ //开始判断是否是回文。
            if(head->val!=tail->val) return false;
            head=head->next;
            tail=tail->next;
        }
        if(head==tail) return true;
        else return true;
        
    
    }
    
    //自己手写的反转链表，不算熟练。
    ListNode* reverse(ListNode* head){
        if(!(head && head->next)) return head;
        
        if(!head->next->next){
            ListNode* a=head;
            ListNode* b=head->next;
            b->next=a;
            a->next=nullptr;
            return b;
        }
        
        ListNode* tmp=head->next;
        ListNode* newhead=reverse(head->next);
        head->next=nullptr;
        tmp->next=head;
        return newhead;
        
    }
};