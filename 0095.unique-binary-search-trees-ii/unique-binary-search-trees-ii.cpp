//自己做出来了！
class Bound{ 
public:
    int low,high;
    bool operator==(const Bound &other) const{
        return low == other.low && high == other.high;
    }
    Bound(int l, int h):low(l),high(h){}
};
namespace std{
    template <>
    struct hash<Bound>{
        size_t operator()(const Bound &k) const
        {
            int h = k.low ^ k.high;
            return h;
        }
    };
}
// https://www.acwing.com/blog/content/9/

class Solution {
public:
    vector<TreeNode*> res;
    int n;
    unordered_map<Bound,vector<TreeNode*>> um; // 本来想优化一下搜索速度，结果加上反倒是慢了
    vector<TreeNode*> generateTrees(int nn) {
        if(nn==0) return res;
        n=nn;
        return dfs(0,n+1);
    }
    
    // 想到了限制左右边界，因为这样才可以限制子树中节点的数目，避免无限延伸(比如3可以是2的夫妻也可以是2的儿子)。
    // 其实也相当于利用了二叉搜索树的性质：
    // 根节点是左子树的上界，是右子树的下界
    vector<TreeNode*> dfs(int low, int high){ 
        Bound b(low,high);
        // if(um.find(b)!=um.end()) return um[b];
        
        vector<TreeNode*> res;
        if(high-low<2){ // 别忘了左子树为空，而右子树不为空的情况
            res.push_back(nullptr);
            return res;
        } 
        if(high-low==2){
            res.push_back(new TreeNode(low+1));
            return res;
        }
        
        for(int i=low+1;i<=high-1;i++){
            auto lset=dfs(low,i);
            auto rset=dfs(i,high);
            for(const auto &l:lset){
                for(const auto &r:rset){
                    if(l && l->val>=i) continue;
                    if(r && r->val<=i) continue;
                    auto root=new TreeNode(i);
                    root->left=l;
                    root->right=r;
                    res.push_back(root);
                }
            }
        }
        // um[b]=res;
        return res;
    }
};

class Solution1 {
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





