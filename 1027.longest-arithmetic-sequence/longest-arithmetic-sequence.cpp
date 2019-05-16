class Solution {
public:
    int res=1;
    vector<unordered_map<int,int>> vec;
    int longestArithSeqLength(vector<int>& A) {
        if(A.size()==0) return 0;
        vec.resize(A.size());
        //vec[0].emplace_back({0,0});
        for(int i=1;i<A.size();i++){
            for(int j=0;j<i;j++){
                int d=A[i]-A[j];
                vec[i][d]=vec[j][d]+1;
                res=max(res,vec[i][d]);
            }
        }
        return res+1;
    }
};