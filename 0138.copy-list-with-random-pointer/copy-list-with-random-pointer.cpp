/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;

    Node() {}

    Node(int _val, Node* _next, Node* _random) {
        val = _val;
        next = _next;
        random = _random;
    }
};
*/
#include<memeory>    
class Solution {
public:
    
    
    Node *copyRandomList(Node *head) {
        if(!head) return nullptr;
        if(um.find(head)!=um.end()) return um[head];
        
        Node *newhead=new Node(head->val,nullptr,nullptr);
        um[head]=newhead;// 注意一定要先做这个，后做递归，否则会有问题，比如它的random是自己，就会死循环
        
        newhead->next=copyRandomList(head->next);
        newhead->random=copyRandomList(head->random);
        // um[head]=newhead;  不可以放在这里，会死循环(比如它的random是自己)
        
        // delete newhead; // 不可以delete
        return um[head];
    }
    

    

// Node *copyRandomList(Node *head) {
// 	if (!head) return NULL;
// 	if (um.find(head) != um.end())
// 		return um.find(head)->second;

// 	Node* node = new Node(head->val);
// 	um[head] = node;
// 	node->next = copyRandomList(head->next);
// 	node->random = copyRandomList(head->random);
// 	return node;
// }

    
    
    Node* copyRandomList2(Node* head) {
        if(!head) return nullptr;
        Node* res=head;
        Node* t=nullptr;
        Node* n=nullptr;
        Node* r=nullptr;
        while(head){
            if(head && um.find(head)==um.end()){
                t=new Node(head->val,nullptr,nullptr);
                um[head]=t;
            }
            t=um[head];
            
            if(head->next && um.find(head->next)==um.end()){
                Node* n=new Node(head->next->val,nullptr,nullptr);
                um[head->next]=n;
            }
            t->next=um[head->next];
            
            if(head->random && um.find(head->random)==um.end()){
                Node* r=new Node(head->random->val,nullptr,nullptr);
                um[head->random]=r;
            }
            t->random=um[head->random];
            
            head=head->next;
        }
        return um[res];
    }
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    //这道题目不难，思路也很好想，但是要考虑全面比较难，特别是想一次写对比较难。
    unordered_map<Node*, Node*> um;
    Node* copyRandomList1(Node* head) {
        if(!head) return nullptr;
        Node *newhead=new Node(-100,nullptr,nullptr); //构造函数要写全参数
        Node *curr=newhead;
        while(head){
            curr->val=head->val;
            um[head]=curr; //放前面，为了处理后面引用自己情况。
            if(head->next){
                Node *n=head->next;
                if(um.find(n)==um.end())
                    um[n]=new Node(n->val,nullptr,nullptr);
                curr->next=um[n];
            }
            if(head->random){
                Node *n=head->random;
                if(um.find(n)==um.end()){
                    um[n]=new Node(n->val,nullptr,nullptr);
                }
                curr->random=um[n];
            }
            head=head->next;
            curr=curr->next;
        }
        return newhead;
    }
    
    
};