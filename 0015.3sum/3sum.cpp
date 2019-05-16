class Solution {
public:
    //完全参考了https://leetcode.com/problems/3sum/discuss/7402/Share-my-AC-C++-solution-around-50ms-O(N*N)-with-explanation-and-comments。
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> result;
        if(nums.size()<3) return result;
        sort(nums.begin(),nums.end());
        for(int i=0;i<nums.size()-1;i++){
            int target=-nums[i];
            int second=i+1;
            int third=nums.size()-1;
            //cout<<"1:"<<i<<" "<<second<<" "<<third<<endl;
            while(second<third){
                int sum=nums[second]+nums[third];
                if(sum<target) second++;
                else if(sum>target) third--;
                else{
                    vector<int> tmp{nums[i],nums[second],nums[third]};
                    result.push_back(tmp);
                    //cout<<"result:"<<nums[i]<<" "<<nums[second]<<" "<<nums[third]<<endl;
                    //cout<<"result_index:"<<i<<" "<<second<<" "<<third<<endl;
                    second++;
                    third--;
                    while(second<third && nums[second]==tmp[1]){
                        second++;
                        //cout<<"2:"<<i<<" "<<second<<" "<<third<<endl;
                    }
                    //cout<<"2':"<<i<<" "<<second<<" "<<third<<endl;
                    while(second<third && nums[third-1]==tmp[2]){
                        third--;
                        //cout<<"3:"<<i<<" "<<second<<" "<<third<<endl;
                    }
                    //cout<<"3':"<<i<<" "<<second<<" "<<third<<endl;
                }
            }
            while(i+1<nums.size() && nums[i]==nums[i+1]){
                i++;
                //注意这里完毕后，在for循环里面还会再+1，这样才避免了重复的问题。
                //cout<<"4:"<<i<<" "<<second<<" "<<third<<endl;
            }
        }
        
        
        return result;
    }
    
    
    //更优雅的解法！！！：https://leetcode.com/problems/3sum/discuss/7438/C++-two-pointes-solution-(easy-way-to-handle-duplicaiton).
};

//  0  1  2  3  4  5
// -4 -1 -1  0  1  2