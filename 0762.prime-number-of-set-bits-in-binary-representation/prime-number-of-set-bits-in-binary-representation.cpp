class Solution {
public:
    // https://www.acwing.com/solution/LeetCode/content/530/
    int countPrimeSetBits(int L, int R) {
        unordered_set<int> us={2,3,5,7,11,13,17,19};
        int res=0;
        for(int i=L;i<=R;i++){
            int tmp=0;
            for(int j=i;j>=1;j>>=1) tmp+=(j&1);
            if(us.find(tmp)!=us.end()) res++;
        }
        return res;
    }
};