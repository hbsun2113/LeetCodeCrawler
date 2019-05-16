/*
 * @lc app=leetcode id=257 lang=cpp
 *
 * [257] Binary Tree Paths
 *
 * https://leetcode.com/problems/binary-tree-paths/description/
 *
 * algorithms
 * Easy (45.28%)
 * Total Accepted:    216.1K
 * Total Submissions: 476.5K
 * Testcase Example:  '[1,2,3,null,5]'
 *
 * Given a binary tree, return all root-to-leaf paths.
 * 
 * Note: A leaf is a node with no children.
 * 
 * Example:
 * 
 * 
 * Input:
 * 
 * ⁠  1
 * ⁠/   \
 * 2     3
 * ⁠\
 * ⁠ 5
 * 
 * Output: ["1->2->5", "1->3"]
 * 
 * Explanation: All root-to-leaf paths are: 1->2->5, 1->3
 * 
 */
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
    vector<string> res;
    vector<string> binaryTreePaths(TreeNode* root) {
        if(!root) return res;
        string part;
        dfs(part,root);
        return res;
    }

    void dfs(string part, TreeNode* root){
        if(!root->left && !root->right){ // 如果是叶子节点
            part+=to_string(root->val);
            res.push_back(part);
            return ;
        }

        // 如果不是叶子节点
        part+=to_string(root->val)+"->";
        if(root->left) dfs(part,root->left);
        if(root->right) dfs(part,root->right);
    }
};

