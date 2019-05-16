class Solution {
public:
    int findPairs(vector<int>& nums, int k) {
        if(k<0) return 0; //k是绝对值。
        unordered_map<int,int> um;
        for(const auto &n:nums) um[n]+=1;
        int result=0;
        if(k!=0){
                for(const auto &n:nums){
                    //cout<<n<<" "<<n-abs(k)<<" "<<um[n-abs(k)]<<endl;
                    if(um[n-k]){
                        result+=1;
                        um[n-k]=0;
                    }
                }
        }
        else{
            for(const auto &n:nums){
                if(um[n]>1) {
                    result+=1;
                    um[n]=1;
                }
                
            }
        }
        return result;
        
    }
};