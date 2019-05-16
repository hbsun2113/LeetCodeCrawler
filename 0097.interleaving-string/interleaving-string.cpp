class Solution {
public:
    //自己没有想出来
    bool isInterleave(string s1, string s2, string s3) {
        if(s1.size()+s2.size()!=s3.size()) return false;
        vector<vector<bool>> mask(s1.size()+1,vector<bool>(s2.size()+1,false));
        mask[0][0]=true;
        for(int i=1;i<=s1.size();i++){
            mask[i][0]= (mask[i-1][0] && s3[i-1]==s1[i-1]);
        }
        for(int j=1;j<=s2.size();j++){
            mask[0][j]= (mask[0][j-1] && s3[j-1]==s2[j-1]);
        }
        for(int i=1;i<=s1.size();i++){
            for(int j=1;j<=s2.size();j++){
                mask[i][j]=((mask[i-1][j] && s1[i-1]==s3[i-1+j]) || (mask[i][j-1] && s2[j-1]==s3[i+j-1]));
            }
        }
        return mask[s1.size()][s2.size()];
    }
};