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
    // 三刷，自己做出来了
    // inorder中序遍历，即先左子树，然后自己，最后右子树
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> res;
        if(!root) return res;
        stack<TreeNode*> s;
        auto t=root;
        while(!s.empty() || t){
            while(t){  
                s.push(t);
                t=t->left;
            }
            
            t=s.top();
            s.pop();
            res.push_back(t->val);
            
            t=t->right;
        }
        
        return res;
    }
    
    // 二刷，没有做出来
    // 中序遍历是这样的顺序：left->root->right
    // 感觉不是很好推导出来，暂时先背下来吧：
    // 1.使用两种数据结构：stack和一个临时节点
    // 2.while的循环条件是while(!s.empty() || t)
    // 3.主体思想是先穷尽左子树，然后打印当前值，看看右子树，最后利用栈返回上层
    vector<int> inorderTraversal2(TreeNode* root) {
        vector<int> res;
        if(!root) return res;
        stack<TreeNode*> s;
        TreeNode* t=root;
        while(!s.empty() || t){
            while(t){
                s.push(t);
                t=t->left;
            }
            
            t=s.top(),s.pop();
            res.push_back(t->val);
            
            t=t->right;
        }
        return res;
    }
    
    

    //迭代的方法。https://www.cnblogs.com/grandyang/p/4297300.html
    vector<int> inorderTraversal1(TreeNode* root) {
        vector<int> result;
        stack<TreeNode*> s;
        TreeNode* p=root;
        while(p!=NULL || !s.empty()){
            while(p){//左儿子优先
                s.push(p);
                p=p->left;
            }
            p=s.top();//没有更左的啦 就要中根啦
            s.pop();
            result.push_back(p->val);
            p=p->right;//然后右儿子
        }
        return result;
    }
    
    
    //注意这种递归方法是没有意义的！！！
    vector<int> inorderTraversal5(TreeNode* root) {
        vector<int> result;
        inorder(result,root);
        return result;
    }
    void inorder(vector<int>& result,TreeNode* root){
        if(!root) return;
        if(root->left) inorder(result,root->left);
        result.push_back(root->val);
        if(root->right) inorder(result,root->right);
    }
};