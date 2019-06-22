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
    // 既然有序，要想二分
    // https://www.acwing.com/solution/LeetCode/content/71/
    ListNode* merge2Lists(ListNode* a, ListNode* b){
        auto res=new ListNode(INT_MIN);
        auto curr=res;
        while(a && b){
            if(a->val<b->val){
                curr->next=new ListNode(a->val);
                curr=curr->next;
                a=a->next;
            }
            else{
                curr->next=new ListNode(b->val);
                curr=curr->next;
                b=b->next;
            }
        }
        if(a) curr->next=a;
        if(b) curr->next=b;
        return res->next;
    }
    ListNode* mergeKLists(vector<ListNode*>& lists){
        if(lists.size()==0) return nullptr;
        if(lists.size()==1) return lists[0];
        
        int mid=lists.size()/2;
        auto l=vector<ListNode*>(lists.begin(),lists.begin()+mid);
        auto r=vector<ListNode*>(lists.begin()+mid,lists.end());
        return merge2Lists(mergeKLists(l),mergeKLists(r));
    }
    
    // 优先队列也可以做这道题，更短，更快
    
    
    // 此方法过于朴素暴力
    ListNode* mergeKLists1(vector<ListNode*>& lists) {
        auto res=new ListNode(INT_MIN);
        auto cur=res;
        bool flag=true;
        while(flag){
            flag=false;
            int pos;
            auto tmp=new ListNode(INT_MAX);
            for(int i=0;i<lists.size();i++){
                auto l=lists[i];
                if(l && tmp->val>l->val){
                    flag=true;
                    tmp->val=l->val;
                    pos=i;
                }
            }
            if(flag){
                cur->next=new ListNode(lists[pos]->val);
                cur=cur->next;
                lists[pos]=lists[pos]->next;
            }
            else break;
        }
        return res->next;
    }
};