class Solution {
public:
    // https://www.cnblogs.com/grandyang/p/5847597.html
    bool validUtf8(vector<int>& data) {
        int cnt=0;
        for(const auto &t:data){
            if(cnt==0){
                if((t>>5)==0b110) cnt=1;
                else if((t>>4)==0b1110) cnt=2;
                else if((t>>3)==0b11110) cnt=3;
                else if((t>>7)) return false; // ???????byte???character
            }
            else{
                if((t>>6)!=0b10) return false;
                cnt--;
            }
        }
        return cnt==0;
    }
};