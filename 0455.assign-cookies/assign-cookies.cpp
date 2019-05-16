/*
 * @lc app=leetcode id=455 lang=cpp
 *
 * [455] Assign Cookies
 *
 * https://leetcode.com/problems/assign-cookies/description/
 *
 * algorithms
 * Easy (48.14%)
 * Total Accepted:    59.8K
 * Total Submissions: 124.3K
 * Testcase Example:  '[1,2,3]\n[1,1]'
 *
 * 
 * Assume you are an awesome parent and want to give your children some
 * cookies. But, you should give each child at most one cookie. Each child i
 * has a greed factor gi, which is the minimum size of a cookie that the child
 * will be content with; and each cookie j has a size sj. If sj >= gi, we can
 * assign the cookie j to the child i, and the child i will be content. Your
 * goal is to maximize the number of your content children and output the
 * maximum number.
 * 
 * 
 * Note:
 * You may assume the greed factor is always positive. 
 * You cannot assign more than one cookie to one child.
 * 
 * 
 * Example 1:
 * 
 * Input: [1,2,3], [1,1]
 * 
 * Output: 1
 * 
 * Explanation: You have 3 children and 2 cookies. The greed factors of 3
 * children are 1, 2, 3. 
 * And even though you have 2 cookies, since their size is both 1, you could
 * only make the child whose greed factor is 1 content.
 * You need to output 1.
 * 
 * 
 * 
 * Example 2:
 * 
 * Input: [1,2], [1,2,3]
 * 
 * Output: 2
 * 
 * Explanation: You have 2 children and 3 cookies. The greed factors of 2
 * children are 1, 2. 
 * You have 3 cookies and their sizes are big enough to gratify all of the
 * children, 
 * You need to output 2.
 * 
 * 
 */
class Solution {
public:
    // 从小到大遍历s，看看是否可以满足当前的g,如果可以则结果加一，并且g也向后移动。否则只单纯移动s,直到找到能满足条件的s。
    // g中小需求尽可能地使用s中小饼干满足，因此是对s从小到大遍历。
    int findContentChildren1(vector<int>& g, vector<int>& s) {
        sort(g.begin(),g.end());
        sort(s.begin(),s.end());
        int i=0,j=0;
        int res=0;
        for(int j=0;j<s.size();j++){
            if(g[i]<=s[j]){
                res++;
                i++;
                if(i==g.size()) return res;
            }
        }
        return res;
    }


    // 从后往前遍历
    // 我想的是充分发挥s中大饼干的作用，尽可能地把它分配给g中需求大的孩子。但是这么做做麻烦了。
    int findContentChildren(vector<int>& g, vector<int>& s) {
        sort(g.begin(),g.end());
        sort(s.begin(),s.end());
        int res=0;
        int j=g.size();
        for(int i=s.size()-1;i>=0;i--){
            auto it = upper_bound(g.begin(),g.begin()+j,s[i]);
            it--;
            if(it>=g.begin()) res++;
            // else return res; // 剪枝：说明s连当前g中最小的需求都无法满足了，因此直接返回结果就行。
            j = distance(g.begin(),it);
        }
        return res;
    }
};

