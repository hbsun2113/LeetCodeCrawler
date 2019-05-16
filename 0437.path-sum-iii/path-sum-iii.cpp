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
    // https://www.cnblogs.com/grandyang/p/6007336.html
    // um记录sum和path条数的对应关系
    // 还是前序和的思想
    int pathSum(TreeNode* root, int sum) {
        unordered_map<int,int> um;
        um[0]=1;
        return helper(root,0,sum,um);
    }
    
    
    
    int helper(TreeNode* root, const int &presum, const int &sum, unordered_map<int,int> &um){
        if(!root) return 0;
        int currentsum=presum+root->val;
        int result=um[currentsum-sum]; // 当前节点作为尾节点，符合的路径数目
        um[currentsum]++;
        result+=helper(root->left,currentsum,sum,um);
        result+=helper(root->right,currentsum,sum,um);
        um[currentsum]--;
        return result;
    }
    
    
    // 这个解法我没有看得很明白：
    // https://leetcode.com/problems/path-sum-iii/discuss/91889/Simple-Java-DFS
    // https://www.cnblogs.com/grandyang/p/6007336.html 解法三
    
    
    
    
    
};
/*
                1
        -2             -3      
    1       3        -2 
-1



*/