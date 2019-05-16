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
    stack<pair<TreeNode*,int>> s;
    TreeNode* recoverFromPreorder(string S) {
        int i=0;
        int pre=0;
        int rootv=0;
        while(i<S.size() && isdigit(S[i])){
            rootv*=10;
            rootv+=(S[i]-'0');
            i++;
        }
        TreeNode* root=new TreeNode(rootv);
        TreeNode* curn=root;
        s.emplace(root,0);
        int tmp=0;
        long long v=0;
        while(i<S.size()){
            while(S[i]=='-'){
                tmp++;
                i++;
            }
            while(isdigit(S[i])){
                v*=10;
                v+=(S[i]-'0');
                i++;
            }
            while(tmp<=s.top().second){
                s.pop();
            }
            curn=s.top().first;
            if(!curn->left){
                curn->left=new TreeNode(v);
                s.emplace(curn->left,tmp);
                pre=tmp;
                tmp=0;
                v=0;
                continue;
            }
            if(curn->left){
                curn->right=new TreeNode(v);
                s.emplace(curn->right,tmp);
                pre=tmp;
                tmp=0;
                v=0;
                continue;
            }
            
        }
        return root;
    }
};