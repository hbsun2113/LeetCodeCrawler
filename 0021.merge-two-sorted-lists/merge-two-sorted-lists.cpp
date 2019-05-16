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
    //自己写的
    // 我是将l2 merge到l1上，如果换种思路：新开个链表，然后将l1和l2 merge到新链表上，实现上会简单一些。如下：
    //https://www.acwing.com/solution/LeetCode/content/69/
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        if(!l1) return l2;
        if(!l2) return l1;
        if(l1->val>l2->val){
            swap(l1,l2);
        }
        ListNode* head=l1;
        cout<<l1->val<<" "<<l2->val<<endl;
        while(l1 && l2){
            if(!l1->next){
                cout<<"yes"<<endl;
                l1->next=l2;
                break;
            }
            if(l1->val<=l2->val && l1->next && l1->next->val>=l2->val){
                ListNode* l1_next=l1->next;
                ListNode* l2_next=l2->next;
                l1->next=l2;
                l2->next=l1_next;
                l1=l2;
                l2=l2_next;
            }
            else{
                l1=l1->next;
            }
        }
        return head;
    }
};