class Solution {
public:
    // 这道题目太trick了
    // https://www.bilibili.com/video/av44622681?from=search&seid=9832553398462612953
    // http://blog.hbsun.top/Foh5Y_mO8d_DBdG_xsh7GZXTxxW9
    // 1位数字有9个，2位数字有90个，三位数字有900个，
    int findNthDigit(int n) {
        
        // 1. 先确定n属于第几位数
        long long i=1,s=9,base=1;//i表示位数，s表示第i位一共有多少个数
        while(n>i*s){
            n-=i*s;
            i++;
            s*=10;
            base*=10;
        }
        
        // 2. 确定n属于第i位数的第几个数，即i属于number
        int number=base+(n+i-1)/i-1; // 注意使用了上取整
        
        // 3. 确定n属于number的第几个数
        int r = (n%i!=0)?n%i:i;
        
        for(int j=0;j<(i-r);j++) number/=10;
        return number%10;
        
    }
};