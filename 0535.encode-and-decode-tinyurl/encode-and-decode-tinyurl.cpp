class Solution {
public:
    Solution(){
        dict = "0123456789abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";
    }

    // Encodes a URL to a shortened URL.
    string encode(string longUrl) {
        if(l2s.find(longUrl)!=l2s.end()) return l2s[longUrl];
        string s="";
        for(int i=0;i<6;i++){
            s+=dict[rand()%dict.size()];
        }
        int idx=0;
        while(l2s.find(s)!=l2s.end()){
            s[idx]=dict[rand()%dict.size()];
            idx=(idx+1)%6;
        }
        l2s[longUrl]=s;
        s2l[s]=longUrl;
        return "http://tinyurl.com/"+s;
    }

    // Decodes a shortened URL to its original URL.
    string decode(string shortUrl) {
        int pos=shortUrl.find_last_of('/');
        string s=shortUrl.substr(pos+1);
        return s2l[s];
    }
    
    unordered_map<string,string> l2s,s2l;
    string dict = "0123456789abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";
    
};

// Your Solution object will be instantiated and called as such:
// Solution solution;
// solution.decode(solution.encode(url));