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
    
    // 迭代版
    ListNode* swapPairs(ListNode* head) {
        ListNode* dummy=new ListNode(INT_MIN);
        dummy->next=head;
        
        auto cur=dummy;
        while(cur){
            auto son=cur->next;
            if(!son) break;
            
            auto grand=son->next;
            if(!grand) break;
            
            cur->next=grand;
            son->next=grand->next;
            grand->next=son;
            
            cur=son;
        }
        
        return dummy->next;
    }
    
    
    // 递归版
    ListNode* swapPairs1(ListNode* f) {
        if(!f || !f->next) return f;
        auto s=f->next;
        auto tail=swapPairs(s->next);
        s->next=f;
        f->next=tail;
        return s;
    }
    
    
    /*
    // 迭代，注意我们转移指针的时候不会跳跃。如果跳跃，我觉得应该是有问题，或者说没有写好。
    ListNode* swapPairs(ListNode* head) {
        ListNode* newhead=new ListNode(-100);
        newhead->next=head;
        ListNode *pre=newhead;
        while(pre){
            ListNode* f=pre->next;
            if(!f) return newhead->next;

            ListNode* s=f->next;
            if(!s) return newhead->next;

            pre->next=s;
            f->next=s->next;
            s->next=f;

            pre=f;
        }
        return newhead->next;




    }



    // 递归做法
    ListNode* swapPairs1(ListNode* head) {
        if(!head) return head;
        ListNode* s=head->next;
        if(!s) return head;
        if(!s->next){// 处理最后两个节点。
            head->next=nullptr;
            s->next=head;
            return s;
        }
        head->next=swapPairs(s->next);
        s->next=head;
        return s;
    }
    */
};