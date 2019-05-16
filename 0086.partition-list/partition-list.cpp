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
    //完全copy别人的 自己做的时候没有想到这种方法 麻烦而且没有做出来。要利用多个指针的时候一定要设计好，要不然实现上太麻烦了！！！！！！啊啊啊啊啊狂躁
    ListNode* partition(ListNode* head, int x) {
        ListNode node1(0),node2(0);
        ListNode *p1=&node1,*p2=&node2;
        while(head){
            if(head->val<x){
                p1=p1->next=head;//先执行p1->next=head;再执行p1=p1->next;
            }
            else{
                p2=p2->next=head;
            }
            head=head->next;
        }
        p2->next=NULL;
        p1->next=node2.next;
        return node1.next;
        
    }
};