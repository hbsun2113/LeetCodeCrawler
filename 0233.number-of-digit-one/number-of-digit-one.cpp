class Solution {
public:
    // yxc的做法：https://www.bilibili.com/video/av41342810?from=search&seid=14185414148974506307
    /* 举例一个数字是12345，可以用abcdef来表示，1(a)2(b)3(c)4(d)5(e)6(f)。用a代表1，用b代表2,以此类推
       现在我们设定c位是1了，我们统计下有多少个合法的ab1def，即ab1def要小于12345，即我们要看c位为1 有多少种合法情况。 
       1.当ab位的范围是[0,ab-1]时，无论如何也不会超过范围(def的范围任选，t是def的总范围)，则1的个数是(ab-1-0+1)*t
       2.当ab位就是ab了，即121def,我们要分情况讨论：
            2.1当真正的c位为0时，121def超过了范围，因此有0个
            2.2当真正的c位为1时，def的范围为[0,def],因此有def+1个
            2.3当真正的c位大于1时，def的范围为[0,999]，因此有t个。
            
       遍历各个位，设置为1，总数就是结果。      
    */ 
    //![直播示意图](https://github.com/hbsun2113/picture/blob/master/20190514_074358000_iOS.png)

    int countDigitOne(int n) {
        vector<int> num;
        while(n>0) num.push_back(n%10),n/=10;
        int res=0;
        for(int i=0;i<num.size();i++){
            int left=0,right=0,t=1; // left是ab right是def
            for(int k=num.size()-1;k>i;k--) left*=10,left+=num[k];
            for(int k=i-1;k>=0;k--) right*=10,right+=num[k],t*=10;
            res+=left*t;
            if(num[i]==1) res+=(right+1);
            if(num[i]>1) res+=t;
        }
        return res;
    }
};