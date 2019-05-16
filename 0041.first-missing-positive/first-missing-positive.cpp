class Solution {
public:
    //感觉这题目也不难啊 easy AC
    int firstMissingPositive(vector<int>& nums) {
        int length=10000;
        bool flag[length];
        for(int i=0;i<length;i++){
            flag[i]=false;
        }
        int minvalue=INT_MAX,maxvalue=INT_MIN;
        for(auto & num:nums){
            if(num>0) flag[num]=true;
            if(num>0 && num<minvalue) minvalue=num;
            if(num>0 && num>maxvalue) maxvalue=num;
        }
        if(minvalue==INT_MAX) return 1;
        for(int i=1;i<10000;i++){
            if(flag[i]==false) return i;
        }
        
    }
};