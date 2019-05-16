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
    
    // 四刷，这个应该不符合题意
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        unordered_set<ListNode *> us;
        while(headA){
            us.emplace(headA);
            headA=headA->next;
        }
        while(headB && us.find(headB)==us.end()) headB=headB->next;
        return headB;
    }
    
    // 二刷,还是做错了。
    // p和q走完相同的路程。如果有交集则在交集的起点相遇；否则都是停留在了tail
    ListNode *getIntersectionNode4(ListNode *headA, ListNode *headB) {
        ListNode *p=headA, *q=headB;
        while(p!=q){
            if(!p) p=headB;
            else p=p->next;
            if(!q) q=headA;
            else q=q->next;
        }
        return p;
    }
    
    
    
    
    // 最简洁且直观的写法
    ListNode *getIntersectionNode3(ListNode *headA, ListNode *headB) {
        ListNode *p = headA, *q = headB;
        while (p != q)
        {
            if (p) p = p->next;
            else p = headB;
            if (q) q = q->next;
            else q = headA;
        }
        return p;
    }
    
    
    //参考了https://www.acwing.com/solution/LeetCode/content/256/ 写的，但还是没有人家简洁。
    ListNode *getIntersectionNode2(ListNode *headA, ListNode *headB) {
        if(!headA && !headB) return nullptr;
        if(!headA || !headB) return nullptr;
        ListNode * p=headA;
        ListNode * q=headB;
        while(true){
            if(!p && !q) return nullptr;
            if(p==q) return p;
            if(!p) p=headB;
            if(!q) q=headA;
            if(p!=q){ //注意要有这步判断，很容易忘掉。
                p=p->next;
                q=q->next;
            }
        }
        return nullptr;
    }
    
    
    
    
    
    
    
    ListNode *getIntersectionNode1(ListNode *headA, ListNode *headB) {
        if(!headA || !headB) return nullptr;
        while(headA){
            ListNode * newB=headB;
            while(newB && (newB)!=(headA)){
                newB=newB->next;
            }
            if(newB==headA) return headA;
            headA=headA->next;
        }
        return nullptr;
    }
};