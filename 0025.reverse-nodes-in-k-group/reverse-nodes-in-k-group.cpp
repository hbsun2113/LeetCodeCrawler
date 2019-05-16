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
    //这种题目调试了很久 感觉是不得其法，有机会看看别人的思路吧。(其实就是觉得这种链表类的问题不是很好调试)
    ListNode* reverseKGroup(ListNode* head, int k) {
        if(head==NULL || k==0 || k==1) return head;
        ListNode* root=head,*pre=NULL;
        int len=0,count=0,time=0;
        while(head!=NULL){
            len+=1;
            head=head->next;
        }
        // cout<<len<<" "<<k<<endl;
        if(len<k) return root;
        ListNode** ListArray=new ListNode* [len]; 
        head=root;
        while(count<len)
        {
            count+=k;
            time=0;
            for(int i=0;i<k;i++){
                if(head!=NULL){
                    // cout<<head->val<<endl;
                    ListArray[i]=head;
                    head=head->next; 
                    time+=1;
                }
            }
            // if(head!=NULL) head=head->next;
            // cout<<ListArray[k-1]->val<<endl;
            if(pre==NULL) root=reversePart(ListArray,time,k);
            else
                pre->next=reversePart(ListArray,time,k);
            pre=ListArray[0];
            // cout<<"E "<<ListArray[0]->next->val<<endl;
        }
        if(time==k) pre->next=NULL;
        ListNode* tmp=root;
        while(tmp!=NULL){
            // cout<<tmp->val<<" "<<endl;
            tmp=tmp->next;
        }
        return root;
        
    } 
    ListNode* reversePart(ListNode* ListArray[],int time,int k){
        if(time==0) return NULL;
        if(time!=k) return ListArray[0];
        for(int i=k-1;i>=1;i--){
            ListArray[i]->next=ListArray[i-1];
        }

        return ListArray[k-1];
    }
    
};