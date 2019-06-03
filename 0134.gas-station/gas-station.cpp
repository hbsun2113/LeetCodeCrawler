class Solution {
 
public:
    
    // 三刷没有做出来，排除法
    /*
    The reason why I think this works:
1, if sum of gas is more than sum of cost, then there must be a solution. And the question guaranteed that the solution is unique(The first one I found is the right one).
2, The tank should never be negative, so restart whenever there is a negative number.
    */
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int sum_gas=accumulate(gas.begin(),gas.end(),0);
        int sum_cost=accumulate(cost.begin(),cost.end(),0);
        if(sum_gas<sum_cost) return -1;
        int res=0,remainder=0;
        for(int i=0;i<gas.size();i++){
            remainder+=(gas[i]-cost[i]);
            if(remainder<0){ // 换起点
                remainder=0;
                res=i+1;
            } 
        }
        return res;
    }
    
    // https://leetcode.com/problems/gas-station/description/ 双指针法也值得借鉴
    int canCompleteCircuit3_2(vector<int>& gas, vector<int>& cost) {
        int n = gas.size();
        vector<int> sum = vector<int>(n * 2, 0);
        for (int i = 0; i < n * 2; i++)
            sum[i] = gas[i % n] - cost[i % n];

        int start = 0, end = 0, tot = 0;
        while (start < n && end <= 2 * n) {
            tot += sum[end];
            while (tot < 0) {
                tot -= sum[start];
                start++;
            }
            if (end - start + 1 == n)
                return start;
            end++;
        }
        return -1;
    }
    
    // 二刷，没有做出来。
    // http://www.cnblogs.com/grandyang/p/4266812.html
    // 如果gas的总量<cost的总量，肯定是走不完全程的，所以直接返回-1。
    // 反之，如果 gas的总量>cost的总量,肯定是可以走完全程的，有解。
    // 但如果在某个点n上，sum是小于0的，那么从起点到这个点的所有点都不可能是起点，因为它们在n上的状态肯定是还不如当前起点在n上的状态的。
    // 想了想，其实这道题目是排除法。
    // 但我不知道为什么是解唯一。 哦现在知道了，是题目自己保证了解唯一
    int canCompleteCircuit2(vector<int>& gas, vector<int>& cost) {
        int sum=0,total=0,start=0;
        for(int i=0;i<gas.size();i++){
            sum+=(gas[i]-cost[i]);
            total+=(gas[i]-cost[i]);
            if(sum<0){
                sum=0;
                start=i+1; //注意是i+1
            }
        }
        if(total<0) return -1;
        return start;
    }
    
    //水题，直接pass。 但我的解法过于粗暴，附上真正的结题思路：https://siddontang.gitbooks.io/leetcode-solution/content/greedy/gas_station.html
    int canCompleteCircuit1(vector<int>& gas, vector<int>& cost) {
        vector<int> start;
        for(int i=0;i<gas.size();i++){
            if(gas[i]>=cost[i]) start.push_back(i);
        }
        for(int s=0;s<start.size();s++){
            int index=start[s];
            int pack=gas[index]-cost[index];
            int i=(index+1)%gas.size();
            while((i!=index) && pack>=0){
                pack+=(gas[i]-cost[i]);
                i=(i+1)%gas.size();
            }
            if(pack>=0) return index;
        }
        return -1;
    }
    
    
    
};