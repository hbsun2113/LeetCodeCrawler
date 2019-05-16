class Solution {
public:
    //不要看英文题目，直接看这个链接吧：http://www.cnblogs.com/grandyang/p/9784690.html
    Solution(vector<int> w) {
        int sum=0;
        for(const auto n:w){
            sum+=n;
            result.emplace_back(sum);
            // cout<<result.back()<<endl;
        }
    }
    
    int pickIndex() {
        int sum=result.back();
        int value=rand()%(sum);
        auto it=upper_bound(result.begin(),result.end(),value);  //只能使用upper_bound，不能使用lower_bound。
        return it-result.begin();
    }
    
    vector<int> result;
};


/**
 * Your Solution object will be instantiated and called as such:
 * Solution obj = new Solution(w);
 * int param_1 = obj.pickIndex();
 */