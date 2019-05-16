class Solution {
public:
    // 二刷没有做出来，是看的一刷的题解。
    // 132 分别对应着 s1\s2\s3
    // 其中关系最紧张的就是s1和s3，要满足s1<s3，而s2只要尽可能得大就行了，没有什么限制它的。
    // 我们想要做的就是在满足s3<s2的情况下，尽可能得增大s3，这样更容易找到满足条件的s1。
    // 本题使用单调递增栈，并且从后往前遍历vector，s3接受的是被弹出的元素，这样就使得s3肯定小于一个值,同时s3在尽可能地增大
    // 然后每遇到一个元素，就看看是否小于s3，如果是那就是找到了132结构
    bool find132pattern(vector<int>& nums) {
        int s3=INT_MIN;
        stack<int> s;
        for(int i=nums.size()-1;i>=0;i--){
            if(nums[i]<s3) return true;
            
            while(!s.empty() && nums[i]>s.top()){
                s3=s.top();
                s.pop();
            }
            s.push(nums[i]);
            
        }
        return false;
    }
};