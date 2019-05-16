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
    // 三刷，做对了
    /*int maxv;
    int rob(TreeNode* root) {
        maxv=0;
        dfs(root);
        return maxv;
    }
    
    vector<int> dfs(TreeNode* root){ //0为包含自己的最大值 1为不包含自己的最大值
        vector<int> res{0,0};
        if(!root) return res;
        auto l=dfs(root->left);
        auto r=dfs(root->right);
        res[0]=root->val+l[1]+r[1];
        res[1]=max(l[0],l[1])+max(r[0],r[1]);
        maxv=max(maxv,max(res[0],res[1]));
        return res;
        
    }*/
    
    // 二刷，没有做对
    long long res=0;
    int rob(TreeNode* root) {
        if(!root) return 0;
        dfs(root);
        return res;
    }


    pair<int,int> dfs(TreeNode* root){  // 第一个是包含自己，第二个是不包含自己
        if(!root) return make_pair<int>(0,0);
        auto l=dfs(root->left);
        auto r=dfs(root->right);

        // 这行代码要注意，这样是错误的:f=l.first+r.first; 
        // f肯定不包含自己，但是它的最优解可能也是不包含儿子节点的。
        long long f=max(l.first,l.second)+max(r.first,r.second);
        
        long long s=root->val+l.second+r.second;
        res=max(res,f);
        res=max(res,s);
        // cout<<s<<" "<<f<<endl;
        return make_pair<int>(s,f);
    }
    
    
    
    //自己没有做出来，这个题解写得不错：https://leetcode.com/problems/house-robber-iii/discuss/79330/step-by-step-tackling-of-the-problem
    int rob3(TreeNode* root) {
        const auto &tmp=helper(root);
        return max(tmp[0],tmp[1]);
    }
    
    vector<int> helper(TreeNode* root){
        vector<int> res(2,0);
        if(!root) return res;
        const auto &l=helper(root->left);
        const auto &r=helper(root->right);
        res[0]=max(l[0],l[1])+max(r[0],r[1]);  //不包含该节点
        res[1]=root->val+l[0]+r[0];
        return res;
    }

    
    
    
    
    unordered_map<TreeNode*,int> um;
    int rob1(TreeNode* root) {
        if(!root) return 0;
        if(um.find(root)!=um.end()) return um[root];
        int tmp=root->val;
        if(root->left)
            tmp+=rob(root->left->left)+rob(root->left->right);
        if(root->right)
            tmp+=rob(root->right->left)+rob(root->right->right);
        um[root]=max(tmp,rob(root->left)+rob(root->right));
        return um[root];
    }
    
    
};