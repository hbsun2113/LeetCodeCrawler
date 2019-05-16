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
    //完全自己做出来的
    ListNode* deleteDuplicates(ListNode* head) {
        if(head==NULL) return NULL;
        //先找到第一个符合条件的点 作为根结点
        while(head->next!=NULL && head->val==head->next->val){
            while(head->next!=NULL && head->val==head->next->val){
                head=head->next;
            }
            if(head!=NULL) head=head->next;
            if(head==NULL) return NULL;
        }
        
        ListNode* result=head;//根结点
        ListNode* valid=head;
        if(head) head=head->next;//看看后续的点是否满足条件
        
        while(head){
            while(head && head->next!=NULL && head->val==head->next->val){
                while(head->next!=NULL && head->val==head->next->val){
                    head=head->next;
                }
                if(head!=NULL) head=head->next;
                if(head==NULL) head=NULL;
            }
            valid->next=head;//此时的head一定不是冗余节点
            valid=head;
            if(head) head=head->next;
        }
        
        return result;
    }
        
    
};