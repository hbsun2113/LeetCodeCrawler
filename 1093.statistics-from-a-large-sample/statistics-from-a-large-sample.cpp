class Solution {
public:
    // 这道题目可以用来求大数据下的中位数，看@hotinherre的评论！
    vector<double> sampleStats(vector<int>& cnts) {
        double res[5] = { 255, 0, 0, 0, 0 };
        int t_cnt = accumulate(begin(cnts), end(cnts), 0), m_cnt = 0;
        int m1 = (t_cnt+1)/2, m2 = (t_cnt+2)/2;  // 这个应该是模板：
        for (auto i = 0, cnt = 0; i < cnts.size(); cnt += cnts[i++]) {
            res[0] = cnts[i] ? min((int)res[0], i) : res[0]; // 统计最小值
            res[1] = cnts[i] ? i : res[1]; // 统计最大值
            res[2] += (double)i * cnts[i] / t_cnt; // 平均值：每个数都要除以总数
      
            // 求中位数比较巧妙：之前的值没到达目标值+加上我就能达到目标值，说明我就是目标值
            if (cnt < m1 && cnt + cnts[i] >= m1) res[3] += (double)i / 2;  
            if (cnt < m2 && cnt + cnts[i] >= m2) res[3] += (double)i / 2;
      
            res[4] = m_cnt < cnts[i] ? i : res[4]; // 众数
            m_cnt = max(m_cnt, cnts[i]);
        }
        return vector<double>(begin(res), end(res));
    }
};