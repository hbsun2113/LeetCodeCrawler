class Solution {
public:
    //自己没想到O(n)的做法，这个单调栈需要借鉴 https://www.acwing.com/solution/LeetCode/content/399/
    // 既和值有关系，又和位置有关系的 要考虑到单调栈的应用
    vector<int> nextGreaterElement(vector<int>& findNums, vector<int>& nums) {
        unordered_map<int,int> um;
        for(int i=0;i<nums.size();i++) um[nums[i]]=i;
        
        stack<int> s; //单调栈
        vector<int> greater(nums.size());  //要来存储第一个比自己大的下标
        
        for(int i=0;i<nums.size();i++){
            while(!s.empty() && nums[i]>nums[s.top()]){
                greater[s.top()]=nums[i];
                s.pop();
            }
            s.push(i);
        }
        
        while(!s.empty()){
            greater[s.top()]=-1;
            s.pop();
        }
        
        vector<int> vec(findNums.size());
        for(int i=0;i<vec.size();i++){
            vec[i]=greater[um[findNums[i]]];
        }
        
        return vec;
    }
};