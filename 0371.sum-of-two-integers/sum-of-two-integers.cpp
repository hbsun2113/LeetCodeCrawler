class Solution {
public:
    // http://www.cnblogs.com/grandyang/p/5451942.html
    // https://www.acwing.com/solution/LeetCode/content/543/

    // 二刷没有做出来，经典题目还是记住为好
    int getSum(int a, int b) {
        if(a==0) return b;
        if(b==0) return a;
        int value=a^b;              // 用 <异或> 来算不带进位的和
        int carry=(uint(a&b))<<1;   // 用 <与> 并 <左移> 一位来算进位
        //int carry=uint((a&b)<<1); // 注意是先转uint再左移
        // cout<<value<<" "<<carry<<endl;
        return getSum(value,carry);
    }
};

/*
    (位运算) O(1)O(1)
用<异或>来算不带进位的和(异或：0⊕0=0，1⊕0=1，0⊕1=1，1⊕1=0)
用<与>并<左移>一位来算进位
递归计算<异或>结果(无进位和)和<相与>结果(进位)的和，直到无需进位
举例：

a=101

b=011

第一步异或，a∧b=110a∧b=110，最右位的和2需要进位；

第二步相与，a&b=001a&b=001，相与出来的结果表示的是需要进位的地方，将它左移一位得到010010；

第三步，递归调用getsum，求110110和010010的和。

时间复杂度O(1)O(1)
空间复杂度O(1)O(1)
第二行原来的版本是 carry = (a&b)<<1，感谢@zeromagic指出问题：

LeetCode现在增强了这道题的数据。上面的做法已经无法AC。
1. 两个数均为负数时，RE。eg. [-2, -3]
2. 当负数的绝对值小于正数时，RE。eg. [-2, 3]
3. 极限数据，RE。eg. [2147483647, -2147483648]

进行如下强转后可AC。
carry = uint(a & b) << 1;
*/

//1:01
//2:10
//3:11

//-2: