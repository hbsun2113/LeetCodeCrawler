/*
 * @lc app=leetcode id=24 lang=cpp
 *
 * [24] Swap Nodes in Pairs
 *
 * https://leetcode.com/problems/swap-nodes-in-pairs/description/
 *
 * algorithms
 * Medium (43.65%)
 * Total Accepted:    294.1K
 * Total Submissions: 672.2K
 * Testcase Example:  '[1,2,3,4]'
 *
 * Given a linked list, swap every two adjacent nodes and return its head.
 * 
 * You may not modify the values in the list's nodes, only nodes itself may be
 * changed.
 * 
 * 
 * 
 * Example:
 * 
 * 
 * Given 1->2->3->4, you should return the list as 2->1->4->3.
 * 
 * 
 */
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
    // 迭代，注意我们转移指针的时候不会跳跃。如果跳跃，我觉得应该是有问题，或者说没有写好。
    ListNode* swapPairs(ListNode* head) {
        ListNode* newhead=new ListNode(-100);
        newhead->next=head;
        ListNode *pre=newhead;
        while(pre){
            ListNode* f=pre->next;
            if(!f) return newhead->next;

            ListNode* s=f->next;
            if(!s) return newhead->next;

            pre->next=s;
            f->next=s->next;
            s->next=f;

            pre=f;
        }
        return newhead->next;




    }



    // 递归做法
    ListNode* swapPairs1(ListNode* head) {
        if(!head) return head;
        ListNode* s=head->next;
        if(!s) return head;
        if(!s->next){// 处理最后两个节点。
            head->next=nullptr;
            s->next=head;
            return s;
        }
        head->next=swapPairs(s->next);
        s->next=head;
        return s;
    }
};

