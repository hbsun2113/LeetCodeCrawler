#define dbv(v) cout << #v << "="; for (auto _x : v) cout << _x << ", "; cout << endl
class Solution {
public:
    int findNumberOfLIS(vector<int>& nums) {
        int n=nums.size();
        vector<int> len(n,1);
        vector<int> count(n,1);
        
        int maxv=0;
        int res=0;
        for(int i=0;i<nums.size();i++){
            for(int j=i-1;j>=0;j--){
                if(nums[i]>nums[j]){ // 这是最基本条件
                    if(len[i]==len[j]+1){ // 说明没有增加长度，累加即可
                        count[i]+=count[j];
                    }
                    else if(len[i]<len[j]+1){ // 说明要增加长度了
                        len[i]=len[j]+1;
                        count[i]=count[j];
                    }
                }
            }

            if(len[i]==maxv) res+=count[i]; // 累加
            else if(len[i]>maxv){ // 重头再来
                maxv=len[i];
                res=count[i];
            }
        }

        return res;
    }
};