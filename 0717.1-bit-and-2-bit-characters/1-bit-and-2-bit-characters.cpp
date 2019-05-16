class Solution {
public:
    //自己没有想出来，因此看了hint。这个问题可能不值得一做？
    bool isOneBitCharacter(vector<int>& bits) {
        if(bits[bits.size()-1]==1) return false;
        return isvalid(bits,0);
    }
    
    bool isvalid(vector<int>& bits,int pos){
        //cout<<pos<<endl;
        if(pos==bits.size()-1 && bits[pos]==0) return true;
        if(pos>=bits.size()) return false;
        if(bits[pos]==0) return isvalid(bits,pos+1);
        else return isvalid(bits,pos+2);
        
    }
};