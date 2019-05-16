class Solution {
 
public:
    // 二刷，没有做出来。
    // http://www.cnblogs.com/grandyang/p/4266812.html
    // 如果gas的总量<cost的总量，肯定是走不完全程的，所以直接返回-1。
    // 反之，如果 gas的总量>cost的总量,肯定是可以走完全程的，有解。
    // 但如果在某个点n上，sum是小于0的，那么从起点到这个点的所有点都不可能是起点，因为它们在n上的状态肯定是还不如当前起点在n上的状态的。
    // 想了想，其实这道题目是排除法。
    // 但我不知道为什么是解唯一。
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
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