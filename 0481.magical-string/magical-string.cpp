class Solution {
public:
    // https://www.acwing.com/solution/LeetCode/content/387/
    // 感觉自己想不出来。
    int magicalString(int n) {
        if(n==0) return 0;
        if(n<=3) return 1;
        vector<int> vec={1,2,2};
        int p=2, res=1, count=3, base=1, num=2; // p是指示的索引，res是1的个数，count是当前的数位。
        while(count<n){
            for(int i=0;i<num;i++){
                vec.push_back(base);
            }
            if(base==1) res+=min(num,n-count); // 最后是可能截断的。
            base=3-base;// 1和2互相转换
            count+=num;
            num=vec[++p];
        }
        return res;
    }
};