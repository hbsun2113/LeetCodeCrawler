class Solution {
public:
    //我是使用map来判断是否有环，下面这个是用快慢指针，也是一个很好的思路啊，活学活用！！
    //https://leetcode.com/problems/happy-number/discuss/56917/My-solution-in-C(-O(1)-space-and-no-magic-math-property-involved-)
    bool isHappy(int n) {
        unordered_map<int,int> um;
        while(n!=1){
            n=helper(n);
            if(um.find(n)!=um.end()) return false;
            um[n]++;
        }
        return true;
    }
    
    int helper(int n){
        int result=0;
        while(n!=0){
            result+=pow(n%10,2);
            n/=10;
        }
        return result;
    }
};