class Solution {
/*
l:(-1,0)
r:(1,0)
up:(0,1);
down:(0,-1)
d: 0 up

   1 l
   2 down
   3 r
   
   -1 r
   -2 down
   -3 l
   
     
*/
public:
    vector<int> dx={0,-1,0,1};
    vector<int> dy={1,0,-1,0};
    int d=0;
    int x=0,y=0;
    // 根据https://www.bilibili.com/video/av52188180?from=search&seid=11390756324119646414的结论：
    // 唯一返回false的条件是：走完一轮后，如果还是方向朝北，但不在原来原来位置。
    // 否则其他的状态都可以视为旋转，经过足够多的轮数时必然会转换来
    
    // 这道题目我当时没有想出来，原因是考虑返回true的条件，但恐怕这个条件太多且复杂。而这道题目应该逆向思维，考虑转不回来的原因，更好些。
    bool isRobotBounded(string instructions) {
        for(const auto &c:instructions){
            helper(c);
        }
        if(!(x==0 && y==0) && d==0) return false;
        return true;
    }
    
    
    void helper(const char &c){
        if(c=='G') x+=dx[abs(d+4)%4],y+=dy[abs(d+4)%4]; // 2. 然后观察规律得到
        else if(c=='L') d++;
        else if(c=='R') d--;
        d%=4; // 1. 首先想的是要把d控制在[-3,3]范围
    }
    // 可能这个更好吧：向左旋转3次即为向右
    
};