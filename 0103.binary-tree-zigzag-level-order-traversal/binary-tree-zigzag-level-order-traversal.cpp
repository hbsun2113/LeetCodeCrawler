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
    // 二刷，思路和“分行从上往下打印二叉树一样”，只是每次都判断一下是否要reverse
    // https://www.acwing.com/problem/content/42/
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> res;
        if(!root) return res;
        queue<TreeNode*> q;
        q.push(root);
        bool flag=true;
        while(!q.empty()){
            vector<int> tmp;
            int size=q.size();
            while(--size>=0){
                auto n=q.front();
                tmp.push_back(n->val);
                q.pop();
                if(n->left)q.push(n->left);
                if(n->right)q.push(n->right);
            }
            if(!flag) reverse(tmp.begin(),tmp.end());
            flag=!flag;
            res.push_back(tmp);
        }
        return res;
    }
    
    //完全自己写的 虽然浪费了一些时间。 自己要画图！！ 思路其实很简单，各维护一个双向队列，注意要是lQ，就是正常顺序，从左到右取就行，从左到右插入；要是rQ，就正好相反从右向左取，从右向左插。
    vector<vector<int>> zigzagLevelOrder1(TreeNode* root) {
        vector<vector<int>> result;
        if(root==NULL) return result;
        deque<TreeNode*> lQ;
        deque<TreeNode*> rQ;
        lQ.push_front(root);
        int node=1;
        bool lfirst=true;
        vector<int> part;
        while(!lQ.empty() || !rQ.empty()){
            if(!lQ.empty()){
                while(!lQ.empty()){
                    TreeNode* tmp=lQ.front();
                    lQ.pop_front();
                    part.push_back(tmp->val);  
                    if(tmp->left){
                        rQ.push_back(tmp->left);
                    }
                    if(tmp->right){
                        rQ.push_back(tmp->right);
                    }
                    
                    
               }
                
                result.push_back(part);
                part.clear();
            }
            if(!rQ.empty()){
                while(!rQ.empty()){
                    TreeNode* tmp=rQ.back();
                    rQ.pop_back();
                    part.push_back(tmp->val);
                    if(tmp->right){
                        lQ.push_front(tmp->right);
                    }
                    if(tmp->left){
                        lQ.push_front(tmp->left);
                    }
               }
                result.push_back(part);
                part.clear();
            }
        }
        return result;
    }
};