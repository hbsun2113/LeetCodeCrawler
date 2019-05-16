class Solution {
public:
    int mySqrt(int x) {
        if(x<=1) return x;
        long long l=0,r=x;
        while(l+1!=r){
            long long mid=l+(r-l)/2;
            if(mid*mid<x) l=mid;
            else r=mid;
        }
        //cout<<x<<" "<<l<<" "<<r<<endl;
        if(r*r==x) return r;
        else return r-1;
    }
    
    // https://www.acwing.com/solution/LeetCode/content/154/
    // 求的是小于等于x的最大值是什么,因此先写出check函数的逻辑是 mid*mid<=x。就是满足条件的逻辑
    // 然后发现答案的解在mid的右侧，因此答案落在右区间，因此使用第二个模板。
    int mySqrt1(int x) {
        int l = 0, r = x;
        while (l < r)
        {
            int mid = (l + 1ll + r) / 2;
            if (mid <= x / mid) l = mid;
            else r = mid - 1;
        }
        return l;
    }
};