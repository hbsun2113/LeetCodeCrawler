class Solution {
public:
    vector<int> grayCode(int n) {
        int len=pow(2,n);
        vector<int> vec;
        int tmp=0;
        for(int i=0;i<len;i++){
            vec.push_back( i^(i>>1) );
        }
        return vec;
    }
};