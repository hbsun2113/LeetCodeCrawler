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
    
    vector<int> postorderTraversal100(TreeNode* root){
        return leftorderTraversal(root);
    }
    
    // 自己再复习一下中序遍历的非递归写法，先左子树->再自己->再右子树。
    // https://www.cnblogs.com/dolphin0520/archive/2011/08/25/2153720.html
    vector<int> leftorderTraversal(TreeNode* root){
        vector<int> vec;
        if(!root) return vec;
        stack<TreeNode*> s;
        while(root || !s.empty()){
            
            while(root){
                s.emplace(root);
                root=root->left;
            }
            
            if(!s.empty()){
                root=s.top();
                s.pop();
                vec.push_back(root->val);
                cout<<root->val<<endl;
                root=root->right;
            }
        }
        return vec;
    }
    
    
    
    
    
    
    
    
    
    
    
    //http://www.cnblogs.com/grandyang/p/4251757.html
    //自己没有做出来，主要是没有想好什么时候去处理根节点
    // 首先确定使用栈结构维护顺序，这样正好逆序。
    // 一定是儿子节点都处理完了，才能处理当前根节点，所以需要一个新变量pre来记录上一个处理的节点，如果上一个处理的是自己的儿子，那么现在就可以处理自己了。因为是使用的是栈结构，所以当自己是栈顶并且上一个处理的是儿子节点时，说明儿子节点们都被处理完了。
    //注意prev不可以初始化为nullptr，因为如果恰好只有右儿子的时候，这样会出错。
    // 如果解释的不明吧，可以再看看上面链接的题解。
    vector<int> res;
    vector<int> postorderTraversal(TreeNode* root) {
        if(!root) return res;
        stack<TreeNode*> s;
        s.emplace(root);
        TreeNode* pre=new TreeNode(-100); //上一个处理的节点
        while(!s.empty()){
            TreeNode* n=s.top();
            if((!n->left && !n->right) || (pre==n->left) || (pre==n->right)){
                res.push_back(n->val);
                s.pop();
                pre=n;
            }
            else{
                if(n->right) s.emplace(n->right);
                if(n->left) s.emplace(n->left);
            }
        }
        return res;
    }
};