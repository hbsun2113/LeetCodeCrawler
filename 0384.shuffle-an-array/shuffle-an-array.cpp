class Solution {
public:
    Solution(vector<int> nums) {
        tmp=ori=nums;
    }
    
    /** Resets the array to its original configuration and return it. */
    vector<int> reset() {
        return ori;
    }
    
    /** Returns a random shuffling of the array. */
    //这道题目的重点就是如何真正的随机：http://www.cnblogs.com/grandyang/p/5783392.html
    //https://yjk94.wordpress.com/2017/03/17/%E6%B4%97%E7%89%8C%E7%9A%84%E6%AD%A3%E7%A1%AE%E5%A7%BF%E5%8A%BF-knuth-shuffle%E7%AE%97%E6%B3%95/
    vector<int> shuffle() {
        for(int i=0;i<tmp.size();i++){
            int j=rand()%(i+1);
            swap(tmp[i],tmp[j]);
        }
        return tmp;
    }
    
    vector<int> ori,tmp;
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution obj = new Solution(nums);
 * vector<int> param_1 = obj.reset();
 * vector<int> param_2 = obj.shuffle();
 */