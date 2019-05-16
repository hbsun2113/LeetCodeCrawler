class Solution {
public:
    // 二刷自己做出来了
    vector<int> countBits(int num) {
        vector<int> res(num+1);
        res[0]=0;
        for(int i=1;i<=num;i++){
            res[i]=res[i/2]+(i&1);
        }
        return res;
    }
    
    // 自己没有做出来 https://www.acwing.com/solution/LeetCode/content/365/
    // 因为每个数i都可以看做是i/2先向左移动一位然后再加上最后一位构成的。
    vector<int> countBits1(int num) {
        vector<int> vec(num+1);
        vec[0]=0;
        for(int i=1;i<=num;i++){
            vec[i]=vec[i>>1]+(i&1);
        }
        return vec;
    }
};