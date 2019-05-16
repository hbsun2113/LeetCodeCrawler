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
    const long long C=1000000007;
    long long res;
    int sumRootToLeaf(TreeNode* root) {
        if(!root) return 0;
        res=0;
        vector<int> tmp;
        dfs(root,tmp);
        return res;
    }
    
    void dfs(TreeNode* root, vector<int> &tmp){
        // cout<<tmp.size()<<endl;
        tmp.push_back(root->val);
        if(!root->left && !root->right){
            long long part=0;
            for(int i=0;i<tmp.size();i++){
                //cout<<tmp[i]<<" ";
                part=(part*2)%C;
                part=(part+tmp[i])%C;
            }
            //cout<<endl;
            res=(res+part)%C;
            tmp.pop_back();
            return ;
        }
        if(root->left){
            dfs(root->left,tmp);
        }
        if(root->right){
            dfs(root->right,tmp);
        }
        tmp.pop_back();
    }
};