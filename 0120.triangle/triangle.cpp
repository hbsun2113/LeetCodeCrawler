class Solution {
public:
    
    // 二更,从下往上节省空间
    // 如果使用一维数组，就不能从上往下。因为会存在利用本层信息的情况
    int minimumTotal(vector<vector<int>>& triangle) {
        if(triangle.size()==0) return 0;
        vector<int> vec(triangle.back());
        for(int i=triangle.size()-2;i>=0;i--){
            const auto &tmp=triangle[i];
            for(int j=0;j<tmp.size();j++){
                vec[j]=min(vec[j+1],vec[j])+triangle[i][j];
            }
        }
        return vec[0];
    }
    
    
    
    

    
    
    // 到底还是做麻烦了 
    // https://leetcode.com/problems/triangle/discuss/38737/Bottom-Up-5-line-C++-Solution
    int minimumTotal3(vector<vector<int>>& triangle) {
        int minvalue=INT_MAX;
        vector<vector<int>> part(triangle);
        part[0][0]=triangle[0][0];
        for(int i=1;i<triangle.size();i++){
            for(int j=0;j<triangle[i].size();j++){
                if(j==0) part[i][j]=part[i-1][j]+triangle[i][j];
                else if(j==triangle[i].size()-1) part[i][j]=part[i-1][j-1]+triangle[i][j];
                else part[i][j]=min(part[i-1][j],part[i-1][j-1])+triangle[i][j];
            }
        }
        for(int i=0;i<part[part.size()-1].size();i++){
            minvalue=min(minvalue,part[part.size()-1][i]);
        }
            
        return minvalue;
        
    }
};