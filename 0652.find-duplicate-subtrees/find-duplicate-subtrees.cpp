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
    // 二刷，还是不熟练啊。中心思想就是要哈希子树。
    vector<TreeNode*> findDuplicateSubtrees(TreeNode* root) {
        helper(root);
        return ans;
    }
    string dfs(TreeNode* root){
        if(!root) return "";
        string cur="";
        cur+=to_string(root->val)+",";
        cur+=dfs(root->left)+",";
        cur+=dfs(root->right)+",";
        um[cur]++;
        if(um[cur]==2) ans.push_back(root);
        return cur;
    }
    
    
    //https://www.acwing.com/solution/LeetCode/content/503/
    vector<TreeNode*> findDuplicateSubtrees1(TreeNode* root) {
        helper(root);
        return ans;
    }
    
    string helper(TreeNode* root){
        if(!root) return "";
        string cur="";
        cur+=to_string(root->val)+",";
        cur+=helper(root->left)+","; //逗号和每个叶子结点下的空结点的位置需要保留。这么写是错误的：if(root->left) cur+=helper(root->left)+",";
        cur+=helper(root->right);
        um[cur]++;
        if(um[cur]==2) 
            ans.push_back(root);
        return cur;
        
    }
    
    
    unordered_map<string,int> um;
    vector<TreeNode*> ans;
    
};