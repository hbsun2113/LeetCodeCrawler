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
    int maxLevelSum(TreeNode* root) {
        if(!root) return 0;
        int res=1;
        long long maxv=root->val;
        queue<TreeNode*> q;
        q.push(root);
        int level=1;
        while(!q.empty()){
            long long sum=0;
            for(int i=q.size()-1;i>=0;i--){
                auto t=q.front();
                q.pop();
                sum+=t->val;
                if(t->left) q.push(t->left);
                if(t->right) q.push(t->right);
            }
            if(maxv<sum){
                maxv=sum;
                res=level;
            }
            level++;
        }
        return res;
    }
};