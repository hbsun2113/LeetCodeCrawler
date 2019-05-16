/*
 * @lc app=leetcode id=77 lang=cpp
 *
 * [77] Combinations
 *
 * https://leetcode.com/problems/combinations/description/
 *
 * algorithms
 * Medium (46.47%)
 * Total Accepted:    191.8K
 * Total Submissions: 411.5K
 * Testcase Example:  '4\n2'
 *
 * Given two integers n and k, return all possible combinations of k numbers
 * out of 1 ... n.
 * 
 * Example:
 * 
 * 
 * Input: n = 4, k = 2
 * Output:
 * [
 * ⁠ [2,4],
 * ⁠ [3,4],
 * ⁠ [2,3],
 * ⁠ [1,2],
 * ⁠ [1,3],
 * ⁠ [1,4],
 * ]
 * 
 * 
 */
class Solution {
public:
    vector<vector<int>> res;
    vector<int> vec;
    vector<vector<int>> combine(int n, int k) {
        for(int i=1;i<=n;i++) vec.push_back(i);
        vector<int> part;
        dfs(n,k,part,0);
        return res;
    }

    void dfs(int n, int k, vector<int> &part, int index){
        if(part.size()==k){
            res.push_back(part);
            return;
        }
        for(int i=index;i<vec.size();i++){
            part.push_back(vec[i]);
            dfs(n,k,part,i+1);
            part.pop_back();
        }
    }
};

