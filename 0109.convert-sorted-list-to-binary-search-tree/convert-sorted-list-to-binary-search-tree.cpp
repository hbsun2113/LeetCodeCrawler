/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    //快慢指针，这道题不算是完全自己做的，看到题目还是想不起来用快慢指针，得别人提示一下才行。
    TreeNode* sortedListToBST(ListNode* head) {
        if(!head) return NULL;
        return build(head,NULL);
    }
    
    TreeNode* build(ListNode* head,ListNode* tail){
        if(head==tail) return NULL;
        ListNode* slow=head;
        ListNode* fast=head;
        while(fast->next!=tail && fast->next->next!=tail){
            slow=slow->next;
            fast=fast->next->next;
        }
        
        cout<<slow->val<<" "<<fast->val<<endl;
        TreeNode * root=new TreeNode(slow->val);
        root->left=build(head,slow);
        root->right=build(slow->next,tail);
        return root;
    }
    
    
    
    
    
};