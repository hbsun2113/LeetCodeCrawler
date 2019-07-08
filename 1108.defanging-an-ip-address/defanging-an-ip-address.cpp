class Solution {
public:
    string defangIPaddr(string a) {
        string res;
        string w="[.]";
        istringstream ins(a);
        while(getline(ins,a,'.')){
            res+=a;
            res+=w;
        }
        res.pop_back();
        res.pop_back();
        res.pop_back();
        
        return res;
    }
};