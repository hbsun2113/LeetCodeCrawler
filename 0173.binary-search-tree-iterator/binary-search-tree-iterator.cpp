/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
//这道题目比较简单，手写直接就过了。再做这道题目的时候，建议不看自己写的老代码，直接再重新做一遍。
class BSTIterator {
public:
    std::vector<int> a;
    int index;
    BSTIterator(TreeNode *root) {
        index=0;
        pass(root);//构造函数里是可以调用其他成员函数的呀。
    }

    /** @return whether we have a next smallest number */
    bool hasNext() {
        if(index<a.size()) return true;
        return false;
    }

    /** @return the next smallest number */
    int next() {
        return a[index++];
    }
    
    void pass(TreeNode *root){
        if(!root) return;
        if(root->left) pass(root->left);
        a.push_back(root->val);
        if(root->right) pass(root->right);
        return ;
    }
    
    
};

/**
 * Your BSTIterator will be called like this:
 * BSTIterator i = BSTIterator(root);
 * while (i.hasNext()) cout << i.next();
 */