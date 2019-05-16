/*
 * @lc app=leetcode id=421 lang=cpp
 *
 * [421] Maximum XOR of Two Numbers in an Array
 *
 * https://leetcode.com/problems/maximum-xor-of-two-numbers-in-an-array/description/
 *
 * algorithms
 * Medium (50.51%)
 * Total Accepted:    34.6K
 * Total Submissions: 68.6K
 * Testcase Example:  '[3,10,5,25,2,8]'
 *
 * Given a non-empty array of numbers, a0, a1, a2, … , an-1, where 0 ≤ ai <
 * 2^31.
 * 
 * Find the maximum result of ai XOR aj, where 0 ≤ i, j < n.
 * 
 * Could you do this in O(n) runtime?
 * 
 * Example:
 * 
 * 
 * Input: [3, 10, 5, 25, 2, 8]
 * 
 * Output: 28
 * 
 * Explanation: The maximum result is 5 ^ 25 = 28.
 * 
 * 
 * 
 * 
 */
// 按位操作，尽可能地每个位置都与自己不同。
// 这个题目比较特殊，我们建立Trie时一定是从高位编码，这样才能保证结果尽可能地大 
// copy https://leetcode.com/problems/maximum-xor-of-two-numbers-in-an-array/discuss/130427/()-92 中的一个讨论给出的答案
// https://www.acwing.com/solution/LeetCode/content/549/ 
class Node{
public:
    int val;
    Node *l, *r;
    bool isend;    
    Node(int v, bool ise=false, Node *left=nullptr, Node *right=nullptr):val(v),isend(ise),l(left),r(right){}
};

class Tree{
Node *root; // 哨兵节点
public:
    Tree(vector<int>& nums){
        root =  new Node(INT_MIN);
        for(const auto &n:nums){
            Build(n);
        }
    }

    void Build(int num){
        Node *tmp=root; 
        for(int i=31;i>=0;i--){
            int p=(num>>i)&1;
            if(p==1){
                if(!tmp->l) tmp->l=new Node(1); //左节点是1
                tmp=tmp->l;
            }
            else{
                if(!tmp->r) tmp->r=new Node(0);
                tmp=tmp->r;
            }
        }
        tmp->isend=true;
        tmp->val=num;
    }

    int find_reverse_num(int num){
        Node *tmp=root;
        for(int i=31;i>=0;i--){
            int p=1-((num>>i)&1);
            // 每个节点至少有一个儿子
            // 优先选择最合适的
            if(p==1){ 
                if(tmp->l) tmp=tmp->l; //
                else tmp=tmp->r;
            }
            else{
                if(tmp->r) tmp=tmp->r;
                else tmp=tmp->l;
            }
        }
        return tmp->val;
    }
};

class Solution {
public:
    int findMaximumXOR(vector<int>& nums) {
        Tree t(nums);
        long long res=INT_MIN;
        for(const auto n:nums){
            long long reverse_num=t.find_reverse_num(n);
            res=max(res,n^reverse_num);
        }
        return res;
    }
};


