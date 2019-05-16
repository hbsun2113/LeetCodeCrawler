/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() {}

    Node(int _val, Node* _left, Node* _right, Node* _next) {
        val = _val;
        left = _left;
        right = _right;
        next = _next;
    }
};
*/
class Solution {
public:
    Node* connect(Node* root) {
        if(!root) return root;
        Node* res=root;
        queue<Node*> q;
        q.push(root);
        while(!q.empty()){
             int size=q.size();
             Node* pre=nullptr;
             while(--size>=0){
                 Node* t=q.front();
                 q.pop();
                 if(pre) pre->next=t;
                 pre=t;
                 if(t->left) q.emplace(t->left);
                 if(t->right) q.emplace(t->right);
             }
        }
        return root;
        
    }
};