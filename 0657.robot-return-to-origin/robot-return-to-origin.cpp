class Solution {
public:
    bool judgeCircle(string moves) {
        int heng=0,shu=0;
        for(const auto &m:moves){
            if(m=='L') heng++;
            if(m=='R') heng--;
            if(m=='U') shu--;
            if(m=='D') shu++;
        }
        return (heng==0)&&(shu==0);
        
    }
};