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
    vector<int> nextLargerNodes(ListNode* head) {
        ListNode* curr=head;
        vector<int> vec;
        while(head){
            vec.push_back(head->val);
            head=head->next;
        }
        vector<int> res(vec.size());
        stack<int> s;
        head=curr;
        s.emplace(0);
        for(int i=1;i<vec.size();i++){
            while(!s.empty() && vec[s.top()]<vec[i]){
                res[s.top()]=vec[i];
                s.pop();
            }
            s.emplace(i);
        }
        return res;
        
        
    }
};