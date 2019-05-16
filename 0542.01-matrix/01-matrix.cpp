/*
 * @lc app=leetcode id=542 lang=cpp
 *
 * [542] 01 Matrix
 *
 * https://leetcode.com/problems/01-matrix/description/
 *
 * algorithms
 * Medium (34.89%)
 * Total Accepted:    38.5K
 * Total Submissions: 110.2K
 * Testcase Example:  '[[0,0,0],[0,1,0],[0,0,0]]'
 *
 * 
 * Given a matrix consists of 0 and 1, find the distance of the nearest 0 for
 * each cell.
 * 
 * The distance between two adjacent cells is 1.
 * 
 * Example 1: 
 * Input:
 * 
 * 0 0 0
 * 0 1 0
 * 0 0 0
 * 
 * Output:
 * 
 * 0 0 0
 * 0 1 0
 * 0 0 0
 * 
 * 
 * 
 * Example 2: 
 * Input:
 * 
 * 0 0 0
 * 0 1 0
 * 1 1 1
 * 
 * Output:
 * 
 * 0 0 0
 * 0 1 0
 * 1 2 1
 * 
 * 
 * 
 * Note:
 * 
 * The number of elements of the given matrix will not exceed 10,000.
 * There are at least one 0 in the given matrix.
 * The cells are adjacent in only four directions: up, down, left and right.
 * 
 * 
 * 
 */
class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& matrix) {
        int row=matrix.size();
        int col=matrix[0].size();
        vector<vector<int>> dis(row,vector<int>(col,INT_MAX));
        queue<pair<int,int>> q;
        for(int i=0;i<row;i++){
            for(int j=0;j<col;j++){
                if(matrix[i][j]==0){
                    q.emplace(i,j);
                    dis[i][j]=0;
                }
                    
            }
        }
        int res=0;
        vector<int> dx={0,0,1,-1};
        vector<int> dy={1,-1,0,0};
        while(!q.empty()){
            int size=q.size();
            while(--size>=0){
                auto n=q.front();
                q.pop();
                if(dis[n.first][n.second]==INT_MAX)
                    dis[n.first][n.second]=res;
                for(int k=0;k<4;k++){
                    int xx=n.first+dx[k];
                    int yy=n.second+dy[k];
                    if(xx>=0 && xx<row && yy>=0 && yy<col && dis[xx][yy]==INT_MAX)
                        q.emplace(xx,yy);
                }
            }
            res++;
        }
        return dis;
    }
};

