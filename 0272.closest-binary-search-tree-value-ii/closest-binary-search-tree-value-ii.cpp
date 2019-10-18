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
    // ????????????AC,??????https://leetcode.com/submissions/detail/264400911/
    
    // ????https://www.cnblogs.com/grandyang/p/5247398.html
    // smaller?????target?????larger?????target????
    // ????????????
    vector<int> closestKValues(TreeNode* root, double target, int k) {
        vector<int> res;
        stack<TreeNode*> smaller,larger;
        while(root){ 
            // if(root) cout<<root->val<<endl;
            if(root->val<target){
                smaller.push(root);
                root=root->right;
            }
            else{
                larger.push(root);
                root=root->left;
            }
        }
        
        while(--k>=0){ // ???res???????????smaller?larger?????smaller?larger??????????
            if(smaller.empty() || (!larger.empty() && larger.top()->val-target<target-smaller.top()->val)){
                res.push_back(larger.top()->val);
                next_larger(larger);
            }
            else{
                res.push_back(smaller.top()->val);
                next_smaller(smaller);
            }
        }
        
        return res;
    }
    
    // ?????smaller.top()??????
    void next_smaller(stack<TreeNode*> &smaller){  // ?????????????????????????????????
        auto root=smaller.top();
        smaller.pop();
        if(root->left){  // ?????????????????????????
            smaller.push(root->left);
            while(smaller.top()->right) smaller.push(smaller.top()->right);
        }
    }
    
    void next_larger(stack<TreeNode*> &larger){
        auto root=larger.top();
        larger.pop();
        if(root->right){
            larger.push(root->right);
            while(larger.top()->left) larger.push(larger.top()->left);
        }
    }
     
};
