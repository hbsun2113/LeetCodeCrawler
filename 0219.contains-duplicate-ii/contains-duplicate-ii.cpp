class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        unordered_map<int,vector<int>> um;
        for(int i=0;i<nums.size();i++){
            int num=nums[i];
            if(um.find(num)!=um.end()){
                auto &part=um[num];
                for(const auto index:part){
                    if(abs(i-index)<=k){
                        //cout<<i<<" "<<index<<endl;
                        return true;
                    }
                }
                part.push_back(i);
            }
            else{
                um[num]=vector<int>();
                um[num].push_back(i);
            }
            
        }
        return false;
    }
};