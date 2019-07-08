/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;

    Node() {}

    Node(int _val, Node* _left, Node* _right) {
        val = _val;
        left = _left;
        right = _right;
    }
};
*/
class Solution {
public:
    // 这道题目是面试头条ai lab时的第二道题目，当场没有debug出来(因为忘了使用构造函数初始化left和right指针了)
    // 回来之后自己做出来了。
    // 其实不难，我们首先要明白只要按照树的中序遍历模板就可以得到从小到大的序列，那么只需要一个pre指针记录前一个节点。当遍历到当前节点(root)时，使pre的right指向root,使root的left指向left就可以了，然后使这个root节点成为pre节点。
    Node* treeToDoublyList(Node* root) {
        if(!root) return root;
        Node* dummy=new Node(INT_MIN);
        
        stack<Node*> s;
        auto pre=dummy;
        
        while(!s.empty() || root){
            while(root){
                s.push(root);
                root=root->left;
            }
            
            root=s.top();
            s.pop();
            
            pre->right=root;
            root->left=pre;
            pre=root;
            
            root=root->right;
        } //当整个链表遍历完，pre指向的就是尾节点
        
        
        // 单独处理头&尾节点
        auto smallest=dummy->right;
        pre->right=smallest;
        smallest->left=pre;
        
        return dummy->right;
    }
    
    
};