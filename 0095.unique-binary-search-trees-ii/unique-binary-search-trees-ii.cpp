/*
 * @lc app=leetcode id=95 lang=cpp
 *
 * [95] Unique Binary Search Trees II
 *
 * https://leetcode.com/problems/unique-binary-search-trees-ii/description/
 *
 * algorithms
 * Medium (35.03%)
 * Total Accepted:    132K
 * Total Submissions: 376.1K
 * Testcase Example:  '3'
 *
 * Given an integer n, generate all structurally unique BST's (binary search
 * trees) that store values 1 ... n.
 * 
 * Example:
 * 
 * 
 * Input: 3
 * Output:
 * [
 * [1,null,3,2],
 * [3,2,null,1],
 * [3,1,null,null,2],
 * [2,1,3],
 * [1,null,2,null,3]
 * ]
 * Explanation:
 * The above output corresponds to the 5 unique BST's shown below:
 * 
 * ⁠  1         3     3      2      1
 * ⁠   \       /     /      / \      \
 * ⁠    3     2     1      1   3      2
 * ⁠   /     /       \                 \
 * ⁠  2     1         2                 3
 * 
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
    // 二刷，没有做出来
    // 这个和一刷的做法一样，但是分析了时空复杂度
    // https://www.acwing.com/solution/LeetCode/content/177/
    // 针对[1,n]中的每个数i，都有可能是根节点。
    // 以i为根节点，我们递归求出其左子树的变化和其右子树的变化，两者组合。
    // 在求子树的变化时，需要知道它的范围，因此要规定左右区间。
    vector<TreeNode*> generateTrees(int n) {
        if(n<=0) return vector<TreeNode*>();
        return dfs(1,n);
    }

     vector<TreeNode*> dfs(int l, int r){
        vector<TreeNode*> vec;
        if(r<l){
            vec.push_back(nullptr);
            return vec;
        }
        for(int i=l;i<=r;i++){
            const vector<TreeNode*> &lt=dfs(l,i-1);
            const vector<TreeNode*> &rt=dfs(i+1,r);
            for(const auto &ln:lt)
                for(const auto &rn:rt){
                    TreeNode* root=new TreeNode(i);
                    root->left=ln;
                    root->right=rn;
                    vec.push_back(root);
                }
        }
        return vec;
    }
    
    
    

    //完全照抄别人的代码：https://siddontang.gitbooks.io/leetcode-solution/content/dynamic_programming/unique_binary_search_trees.html
    vector<TreeNode*> generateTrees1(int n) {
        vector<TreeNode*> nullvcector;
        if(n==0) return nullvcector;
        return generate(1,n);
    }
    
    vector<TreeNode*> generate(int start,int end){
        vector<TreeNode*> result;
        
        if(start>end){
            result.push_back(NULL);
            return result;
        }
        for(int i=start;i<=end;i++){
            auto l=generate(start,i-1);
            auto r=generate(i+1,end);
            for(int m=0;m<l.size();m++){
                for(int n=0;n<r.size();n++){
                    TreeNode* root=new TreeNode(i);
                    root->left=l[m];
                    root->right=r[n];
                    result.push_back(root);
                }
            }
        }
        return result;
    }
};

