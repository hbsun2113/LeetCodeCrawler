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
    // ???????????????O(1)????????????????????
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* head=new ListNode(-1);
        auto cur=l1;
        head->next=cur;
        int carry=0;
        
        while(l1 || l2 || carry!=0){
            if(l1){
                carry+=l1->val;
                l1=l1->next;
            } 
            if(l2){
                carry+=l2->val;
                l2=l2->next;
            } 
            cur->val=carry%10;
            carry/=10;
            if(l1) cur->next=l1;
            else if(l2) cur->next=l2;
            else if(carry) cur->next=new ListNode(carry);
            cur=cur->next;
        }
        return head->next;
    }
    
    
    ListNode* addTwoNumbers1(ListNode* l1, ListNode* l2) {
        ListNode *newhead=new ListNode(INT_MIN);
        auto cur=newhead;
        
        int carry=0;
        while(l1 && l2){
            int t=l1->val+l2->val+carry;
            cur->next=new ListNode(t%10);
            carry=t/10;
            l1=l1->next;
            l2=l2->next;
            cur=cur->next;
            
        }
        while(l1){
            int t=l1->val+carry;
            cur->next=new ListNode(t%10);
            carry=t/10;
            l1=l1->next;
            cur=cur->next;
        }
        while(l2){
            int t=l2->val+carry;
            cur->next=new ListNode(t%10);
            carry=t/10;
            l2=l2->next;
            cur=cur->next;
        }
        while(carry){
            cur->next=new ListNode(carry%10);
            carry=carry/10;
        }
        
        return newhead->next;
    }
    
    ListNode* reverse(ListNode* root){
        if(!root || !root->next) return root;
        auto t=root->next;
        auto res=reverse(t);
        t->next=root;
        root->next=nullptr;
        return res;
    }
};