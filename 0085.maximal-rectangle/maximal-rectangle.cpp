class Solution {
public:
    //二更，又没有做出来，参照之前AC的代码了。(时隔一年)
    int maximalRectangle(vector<vector<char>>& matrix) {
        if(matrix.size()==0) return 0;
        
        int result=INT_MIN;
        vector<vector<int>> height(matrix.size(),vector<int>(matrix[0].size()));
        
        //针对每行构造直方图
        for(int i=0;i<matrix.size();i++){
            for(int j=0;j<matrix[i].size();j++){
                if(matrix[i][j]=='0') height[i][j]=0;
                else height[i][j]= i==0?1:height[i-1][j]+1;
                // cout<<height[i][j]<<" ";
            }
            // cout<<endl;
        }
        
        //针对每行确定最大直方图的面积
        for(int i=0;i<matrix.size();i++){
            result=max(result,maxrec(height[i]));
        }
        
        return result;
        
    }
    
    //这个是另一道题目的答案：https://leetcode.com/problems/largest-rectangle-in-histogram/description/
    int maxrec(vector<int> &height){
        int result=INT_MIN;
        stack<int> s;
        height.emplace_back(0);
        int index=0;
        while(index<height.size()){
            if(s.empty() || height[index]>height[s.top()]) s.emplace(index++);
            else{
                int bar=s.top();
                s.pop();
                int width=s.empty()?index:index-s.top()-1;
                int area=width*height[bar];
                result=max(result,area);
            }
        }
        
        return result;
        
        
    }

    
    
};