class Codec {
public:
    // https://www.cnblogs.com/grandyang/p/5265628.html
    // ????????????????????????? ???+"/"? ????????????????
    // Encodes a list of strings to a single string.
    string encode(vector<string>& strs) {
        string res="";
        for(const auto &s:strs)
            res+=to_string(s.size())+"/"+s;
        return res;
    }

    // Decodes a single string to a list of strings.
    vector<string> decode(string s) {
        vector<string> res;
        int i=0;
        while(i<s.size()){
            int found=s.find('/',i);
            int len=stoi(s.substr(i,found-i));
            res.push_back(s.substr(found+1,len));
            i=found+len+1;
        }
        return res;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.decode(codec.encode(strs));