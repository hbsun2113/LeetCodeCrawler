/**
 * Definition for binary tree with next pointer.
 * struct TreeLinkNode {
 *  int val;
 *  TreeLinkNode *left, *right, *next;
 *  TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
 * };
 */
class Solution {
public:
    //代码风格十分不好 后续看看别人是如何做的吧。
    /*void connect(TreeLinkNode *root) {
        if(!root || !root->left) return;
        int nums=1;
        int i=0;
        queue<TreeLinkNode*> q;
        vector<TreeLinkNode*> row;
        row.resize(nums);
        q.push(root);
        while((!q.empty()) && (i<=nums)){
             if(i==nums){
                 for(int j=0;j<i-1;j++)
                     row[j]->next=row[j+1];
                 i=0;
                 nums*=2;
                 row.clear();
                 row.resize(nums);
             }
             TreeLinkNode* temp = q.front();
             q.pop();
             row[i++]=temp;
             if(temp->left){
                 q.push(temp->left);
                 q.push(temp->right);
             }
        }
        for(int j=0;j<i-1;j++)
            row[j]->next=row[j+1];
    }*/
    
    //完全参考了Discuss
    void connect(TreeLinkNode *root) {
        if(!root) return ;
        TreeLinkNode * pre=root;//父节点
        TreeLinkNode * cur=NULL;
        while(pre->left){//只要还有下一层
            cur=pre; //开始循环处理父节点层。
            while(cur){//处理子节点层。
                cur->left->next=cur->right;
                if(cur->next)cur->right->next=cur->next->left;
                cur=cur->next;
            }
            pre=pre->left;
        }
    }
    
    
    
};