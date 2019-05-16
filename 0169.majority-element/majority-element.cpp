class Solution {
public:
    // 二刷
    int majorityElement2(vector<int>& nums) {
        int res=nums[0],count=0;
        for(int i=1;i<nums.size();i++){
            if(res==nums[i]){
                count++;
            }
            else{
                if(count>0) count--;
                else res=nums[i];
            }
        }
        return res;
    }
    
    int majorityElement1(vector<int>& nums) {
        unordered_map<int,int> count;
        int sum=nums.size();
        for(auto & num:nums){
            if(count.find(num)==count.end()) count[num]=1;
            else count[num]+=1;
            if(count[num]>sum/2) return num;
        }
        return 0;
    }
    
    //https://segmentfault.com/a/1190000003740925这里面的投票法，但我觉得叫做抵消法更合适吧。
    int majorityElement(vector<int>& nums) {
        int count=0,candidate=nums[0];
        for(auto &num:nums){
            if(count==0){
                candidate=num;
                count=1;
            }
            else if(candidate==num) count+=1;
            else count-=1;
        }
        return candidate;
    }
};