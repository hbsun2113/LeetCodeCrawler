#include <bits/stdc++.h>
using namespace std;
#define db(x) cerr << #x << "=" << x << endl
#define db2(x, y) cerr << #x << "=" << x << "," << #y << "=" << y << endl
#define db3(x, y, z) cerr << #x << "=" << x << "," << #y << "=" << y << "," << #z << "=" << z << endl
#define dbv(v) cerr << #v << "="; for (auto _x : v) cerr << _x << ", "; cerr << endl


class Solution {
public:
    // 看disucss吧
    // 注意位操作&的优先级非常低，需要处处加括号
    void wiggleSort(vector<int>& nums) {
        for(int i=1;i<nums.size();i++){
            // cout<<(i&1)<<endl;
            if((((i&1)==1)&&(nums[i]<nums[i-1])) || (((i&1)==0)&&(nums[i]>nums[i-1])))
                swap(nums[i-1],nums[i]);
        }
       
        
    }
};