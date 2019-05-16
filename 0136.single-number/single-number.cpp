class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int res=0; //0和任何数字抑或之后都是自己，这个事情想想就对。
        for(const auto n:nums){
            res^=n;
        }
        // for(int i=-10;i<1000;i++){
        //     cout<<(i^0)<<" ";
        // }
        return res;
    }
};

