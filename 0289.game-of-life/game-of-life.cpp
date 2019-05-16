class Solution {
public:
/*
先确定die是0,live是1，都是使用1-bit表示。然后下面是状态转换：
00(0):die<-die
01(1):die<-live
10(2):live<-die
11(3):live<-live
*/ 
    //自己也做出来了，但是感觉这个思路挺巧妙的。
    //https://leetcode.com/problems/game-of-life/discuss/73223/Easiest-JAVA-solution-with-explanation
    int row,col;
    void gameOfLife(vector<vector<int>>& board) {
        row=board.size();
        col=board[0].size();
        for(int i=0;i<row;i++){
            for(int j=0;j<col;j++){
                liveOrDie(board,i,j);
            }
        }
        for(int i=0;i<row;i++){
            for(int j=0;j<col;j++){
                board[i][j]=board[i][j]>>1;
            }
        }
        
    }
    
    int countLiveNeighbor(vector<vector<int>>& board,int i,int j){
        int count=0;
        for(int x=max(0,i-1);x<=min(row-1,i+1);x++){
            for(int y=max(0,j-1);y<=min(col-1,j+1);y++){
                if(board[x][y]&1) count++;
            }
        }
        count-=(board[i][j]&1);
        return count;
    }
    
    void liveOrDie(vector<vector<int>>& board,int i,int j){
        int count=countLiveNeighbor(board,i,j);
        if((board[i][j]&1)==1 && count>=2 && count<=3) board[i][j]=3;
        if((board[i][j]&1)==0 && count==3) board[i][j]=2;
    }
};