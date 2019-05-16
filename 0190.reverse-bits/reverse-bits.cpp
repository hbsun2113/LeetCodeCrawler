class Solution {
public:
    //https://www.cnblogs.com/grandyang/p/4321355.html
    uint32_t reverseBits(uint32_t n) {
        uint32_t result=0;
        for(int i=0;i<32;i++){ //注意是用for循环处理32次，而不是用while(n!=0)进行处理。(其实是移动31次hhh)
            result<<=1; //肯定要移动32次，所以先移动，后++。
            if(n&1) result++;
            n>>=1;
        }
        return result;
    }
    

    
};