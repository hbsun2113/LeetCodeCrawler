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
    // 二刷的时候没有做出来。
    
    
    
    
    
    
    
    
    
    //画个图就可以了。
    ListNode* insertionSortList(ListNode* head) {
        if(!head || !head->next) return head;
        ListNode* newhead=new ListNode(INT_MIN);
        ListNode* l=head;
        while(l){
            ListNode* sl=newhead;
            ListNode *nl=l->next;
            while(sl->next && sl->next->val<l->val) sl=sl->next;
            l->next=sl->next;
            sl->next=l;
            l=nl;
        }
        return newhead->next;
    }
};