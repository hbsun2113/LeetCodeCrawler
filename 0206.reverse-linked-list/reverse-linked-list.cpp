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
    // 多刷，这次写得挺快的，都是一把过，而且我觉得很规范：
    // 这种东西感觉不是每次硬写的，要记住大致思路。
    // 比如递归法记住每次是返回头节点；迭代法是最外面需要定义两个节点(curr和pre)，while里面需要记录下一个节点(next)，然后节点是按顺序转移，不会"跳转"
    // 递归写法
    ListNode* reverseList3(ListNode* head) {
        if(!head || !head->next) return head;
        ListNode* nn=head->next;
        ListNode* newhead=reverseList(nn);
        nn->next=head;
        head->next=nullptr;
        return newhead;
    }
    // 迭代法
    ListNode* reverseList4(ListNode* head) {
        ListNode* pre=nullptr;
        ListNode* first=head;
        while(first){
            ListNode* second=first->next;
            first->next=pre;
            pre=first;
            first=second;
        }
        return pre;
    }
    
    
    
    
    
    //https://www.acwing.com/solution/LeetCode/content/316/
    //比我的优雅，因为它先增加了一个nullptr作为头结点。
    ListNode* reverseList(ListNode* head){
        ListNode* pre=nullptr;
        ListNode* cur=head;
        while(cur){
            ListNode *nnext=cur->next;
            cur->next=pre;
            pre=cur;
            cur=nnext;
        }
        return pre;
    }
    
    
    
    
    //迭代,自己写的
    ListNode* reverseList2(ListNode* head) {
        if(!head || !head->next) return head;
        ListNode* f=head; //first
        ListNode* prev=nullptr;
        while(f && f->next){
            ListNode* s=f->next; //second
            ListNode* t=s->next;
            s->next=f;
            f->next=prev;
            prev=s;
            f=t;
        }
        //长度为奇偶分别处理
        if(!f) return prev;
        f->next=prev;
        return f;
    }
    
    
    
    
    //递归解法，自己写的
    ListNode* reverseList1(ListNode* head) {
        if(!head) return head;
        if(!head->next) return head;
        ListNode* forward=head->next;
        ListNode* newhead=reverseList(forward);
        forward->next=head;
        head->next=nullptr;
        return newhead;
    }
};