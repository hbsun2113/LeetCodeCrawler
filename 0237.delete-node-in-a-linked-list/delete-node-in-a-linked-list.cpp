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
    //这道题目比较奇葩，没有必要做！！！！！！
    void deleteNode(ListNode* node) {
        *node=*(node->next);
        
    }
};