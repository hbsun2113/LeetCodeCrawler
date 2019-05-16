class Solution {
public:
    //这个还是比较简单的 一遍过
    vector<int> plusOne(vector<int>& digits) {
        int length=digits.size();
        if(length==0) return digits;
        int index=length-1;
        int carry=0;
        while(index>=0){
            int result;
            if(index==length-1) digits[index]+=1;
            result=(digits[index]+carry)%10;
            carry=(digits[index]+carry)/10;
            digits[index]=result;
            index--;
        }
        if(carry>0) digits.insert(digits.begin(),1);
        return digits;
    }
};