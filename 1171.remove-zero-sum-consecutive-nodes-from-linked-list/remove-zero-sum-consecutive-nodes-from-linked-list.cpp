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
    // https://leetcode.com/problems/remove-zero-sum-consecutive-nodes-from-linked-list/discuss/366350/C%2B%2B-O(n)-(explained-with-pictures)/330692
    // ?????????????
    ListNode* removeZeroSumSublists(ListNode* head) {
        ListNode* dummy=new ListNode(0); // ?????????
        dummy->next=head;
        unordered_map<int,ListNode*> um;
        int presum=0;
        auto cur=dummy;
        while(cur){
            presum+=cur->val;
            if(um.find(presum)!=um.end()){
                auto start=um[presum];
                auto tmp=um[presum]->next;
                int key=presum; // ??????3????????????????
                while(tmp!=cur){ // ??????????
                    key+=tmp->val;
                    um.erase(key);
                    tmp=tmp->next;
                }
                start->next=cur->next; // ???
            }
            else{
                um[presum]=cur;
            }
            cur=cur->next;
        }
        return dummy->next;
    }
};