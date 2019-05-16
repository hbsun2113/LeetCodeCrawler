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
    //完全自己做的，10min左右AC。
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        if(nums.size()==0) return NULL;
        if(nums.size()==1) return new TreeNode(nums[0]);
        if(nums.size()==2){
            TreeNode * root=new TreeNode(nums[1]);
            root->left= new TreeNode(nums[0]);
            return root;
        }
        int root_index=nums.size()/2;//之前是int root_index=nums.size()/2-1;不行是错的，因为／本身就是取地板。
        TreeNode * root=new TreeNode(nums[root_index]);
        vector<int> l;
        vector<int> r;
        for(int i=0;i<root_index;i++){
            l.push_back(nums[i]);
        }
        for(int i=root_index+1;i<nums.size();i++){
            r.push_back(nums[i]);
        }
        root->left=sortedArrayToBST(l);
        root->right=sortedArrayToBST(r);
        return root;
         
    }
};