/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:
// 自己写的，这个可能更简单些：https://leetcode.com/problems/serialize-and-deserialize-binary-tree/discuss/74259/Recursive-preorder-Python-and-C++-O(n)
    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        string res=s_helper(root);
        // cout<<res<<endl;
        return res;
    }
    // 空为#，使用逗号(',')进行分隔
    string s_helper(TreeNode* root){
        string res="";
        if(!root) return "#,";
        res+=to_string(root->val);
        res+=',';
        res+=s_helper(root->left);
        res+=s_helper(root->right);
        // cout<<res<<endl;
        return res;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        int i=0;
        return d_helper(data,i);
        
    }
    
    TreeNode* d_helper(string data, int& i){
        if(i>=data.size()) return nullptr;
        while(data[i]==',') i++;
        if(data[i]=='#'){
            i+=1;
            return nullptr;
        }
        while(data[i]==',') i++;
        int val=0;
        int flag=1;
        if(data[i]=='-'){
            flag=-1;
            i++;
        }
        while(data[i]!=','){
            cout<<data[i]<<endl;
            val*=10;
            val+=(data[i++]-'0');
        }
        TreeNode* root=new TreeNode(val*flag);
        TreeNode* left=d_helper(data,i);
        TreeNode* right=d_helper(data,i);
        root->left=left;
        root->right=right;
        return root;
    }
    
};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.deserialize(codec.serialize(root));