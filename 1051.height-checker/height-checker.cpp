class Solution {
public:
    int heightChecker(vector<int>& heights) {
        auto tmp(heights);
        sort(tmp.begin(),tmp.end());
        int res=0;
        for(int i=0;i<heights.size();i++){
            if(tmp[i]!=heights[i]) res++;
        }
        return res;
    }
};