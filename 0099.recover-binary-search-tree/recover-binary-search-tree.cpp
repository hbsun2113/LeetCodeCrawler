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

    

    
    
    //递归做法，自己没有做出来，参考了 https://leetcode.com/problems/recover-binary-search-tree/discuss/32535/No-Fancy-Algorithm-just-Simple-and-Powerful-In-Order-Traversal
    //思路很巧妙：
    // 首先中序遍历正好是有序的，因此如果树没有问题，我们的遍历顺序正好是从小到大，每一个元素都比之前的元素要大。
    // 现在考虑在这个有序数组中有两个元素交换了顺序,则不满足了顺序关系，则第一个元素是比自己后面的元素大的，第二个元素是比自己前面元素小的。
    // 因此，我们在中序遍历树的过程中，每次比较"当前元素"和"前一个元素"的大小，如果不满足顺序关系，则第一个元素就是"前一个元素",第二个元素就是"当前元素"。
    //以上题解出自discuss里的讨论：
    //Q:the basic idea is to find the two roots that's needed to swap. We use in-order traversal to detect whether each node is in the right order or not. My question is, if pre.val >= root.val happens, how is it so certain that the invalid nodes are prev in the first time and root in the second time? I can only tell that if pre.val >= root.val happens, the two nodes pre and root are all suspect ones in each time. Can you please it a little bit?
    //A:Imaging a sorted array with two elements swapped, the first problematic element must be the one which is greater than the element right after it, and the second problematic element must be the one which is less than the element right before it. This shouldn't be difficult to visualise.
    // 注意这个解法也不符合题意，因为递归使用了O(n)的空间
    TreeNode* fir=nullptr;
    TreeNode* sec=nullptr;
    TreeNode* prev=new TreeNode(INT_MIN);
    void recoverTree(TreeNode* root) {
        inorder(root);
        swap(fir->val,sec->val);
    }
    
    void inorder(TreeNode* root){
        if(!root) return;
        
        inorder(root->left);
        
        if(!fir && prev->val>root->val){
            fir=prev;
        }
        
        if(fir && prev->val>root->val){
            sec=root;
        }
        
        prev=root;
        
        inorder(root->right);
    }
    
    
    
    
    //只能使用Morris Traversal。先看https://www.cnblogs.com/AnnieKim/archive/2013/06/15/morristraversal.html
    //然后看https://leetcode.com/problems/recover-binary-search-tree/discuss/32535/No-Fancy-Algorithm-just-Simple-and-Powerful-In-Order-Traversal
    //再看https://leetcode.com/problems/recover-binary-search-tree/discuss/32535/No-Fancy-Algorithm-just-Simple-and-Powerful-In-Order-Traversal
    // 如果以后发现Morris Traversal用的多，这题代码争取敲一遍。
    
    
    
    // 暴力解法二刷
    /*vector<int> vec;
    int count;
    void recoverTree(TreeNode* root) {
        TreeNode* curr=root;
        count=0;
        inorder_traverse(curr);

        sort(vec.begin(),vec.end());
        curr=root;
        count=0;
        rebuild(curr);
        return;
    }

    void inorder_traverse(TreeNode* root){
        if(!root) return ;
        if(root->left) inorder_traverse(root->left);
        vec.push_back(root->val);
        // cout<<root->val<<endl;
        if(root->right) inorder_traverse(root->right);
        return ;
    }

    void rebuild(TreeNode* root){
        if(root->left) rebuild(root->left);
        root->val=vec[count++];
        if(root->right) rebuild(root->right);
        return ;
    }*/
    
    
    //暴力解法，使用了O(n)空间
    vector<int> vec;
    int count;
    void recoverTree1(TreeNode* root) {
        TreeNode* head=root;
        help(root);
        root=head;
        count=0;
        update(root);
    }
    
    void help(TreeNode* root){
        if(!root) return;
        if(root->left) help(root->left);
        vec.push_back(root->val);
        if(root->right) help(root->right);
        sort(vec.begin(),vec.end());
    }
    
    void update(TreeNode* root){
        TreeNode* head=root;
        if(!root) return;
        if(root->left) update(root->left);
        root->val=vec[count++];
        if(root->right) update(root->right);
    }
};