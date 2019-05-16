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
    //总是忘记merge排序的过程，看了题解才能想起来：先排序后归并
    //https://www.acwing.com/activity/content/problem/content/13/1/
    //1. 先将母串从中间断开，分为长度相等的字串
    //2. 然后分别将将两个字串进行排序
    //3. 将两个字串merge为一个大串。
    ListNode* sortList(ListNode* head) {
        if(!head || !head->next) return head;
        ListNode* s=head;
        ListNode* f=head;
        while(f->next && f->next->next){
            s=s->next;
            f=f->next->next;
        }
        f=s->next;
        s->next=nullptr;
        s=head;
        
        s=sortList(s); // 注意用返回值给s重新赋值，这里一开始忘记了，还调试了一会儿，教训就是以后想清楚再开始敲代码。
        f=sortList(f);
       
        return merge(s,f);
    }
    
    ListNode* merge(ListNode* s, ListNode* f){
        ListNode* head=new ListNode(INT_MIN);
        ListNode* result=head;
        while(s && f){
            if(s->val<f->val){
                head->next=s;
                s=s->next;
            }
            else{
                head->next=f;
                f=f->next;
            }
            head=head->next;
        }
        if(s) head->next=s;
        else head->next=f;
        return result->next;
    }
    
    
    
    //先实现了一下插入排序，但是时间复杂度不符合题目要求。
    ListNode* sortList1(ListNode* head) {
        ListNode* newhead=new ListNode(INT_MIN);
        ListNode* curr=newhead;
        while(head){
            ListNode* nhead=head->next;
            while(curr->next && curr->next->val<head->val) curr=curr->next;
            head->next=curr->next;
            curr->next=head;
            curr=newhead;
            head=nhead;
        }
        return newhead->next;
    }
};