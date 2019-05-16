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
    //这个解法感觉也挺丑的，参考的是这个 https://www.acwing.com/solution/LeetCode/content/207/
    //看看人家https://leetcode.com/problems/two-sum-iv-input-is-a-bst/discuss/106059/JavaC++-Three-simple-methods-choose-one-you-like
    vector<int> vec;
    bool findTarget(TreeNode* root, int k) {
        inorder(root);
        return binary_seach(k);
    }
    
    void inorder(TreeNode* root){
        if(!root) return ;
        if(root->left) inorder(root->left);
        vec.push_back(root->val);
        if(root->right) inorder(root->right);
    }
    
    // 注意这个二分和我熟悉的优点不一样
    bool binary_seach(int k){
        int l=0,r=vec.size()-1;
        while(l!=r){
            if(vec[l]+vec[r]==k) return true;
            if(vec[l]+vec[r]<k) l++;
            else r--;
        }
        return false;
    }
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    //最暴力的解法，针对每个节点都重新搜索一遍树。
    unordered_map<TreeNode*,bool> um;
    TreeNode* head;
    bool findTarget1(TreeNode* root, int k) {
        head=root;
        return findfirst(root,k);
    }
    
    bool findfirst(TreeNode* root, int k) {
        if(!root) return false;
        um[root]=true;
        if(findsecond(head,k-root->val)) return true;
        um[root]=false;
        if(root->left && findfirst(root->left,k)) return true;;
        if(root->right && findfirst(root->right,k)) return true;
        return false;
    }
    
    bool findsecond(TreeNode* root, int k){
        if(!root) return false;
        if(root->val==k){
            if(!um[root]) return true;
            return false;
        }
        if(root->val>k) return findsecond(root->left,k);
        return findsecond(root->right,k);
    }
    

};