class Solution {
public:
    // 只能说希望下次可以自己做出来了
    // https://www.cnblogs.com/grandyang/p/8440087.html
    vector<string> res;
    vector<string> ipToCIDR(string ip, int n) {
        istringstream ins(ip);
        long long x=0;
        while(getline(ins,ip,'.')){
            x*=256;
            x+=stoi(ip);
        }
        // cout<<std::bitset<32>(x)<<endl;
        
        while(n>0){
            long long step=x&(-x);
            while(step>n) step/=2;
            convert(x,step);
            x+=step;
            n-=step;
        }
        
        return res;
        
    }
    
    void convert(long long x, int step){
        string s=to_string((x>>24)&255)+"."+to_string((x>>16)&255)+"."+to_string((x>>8)&255)+"."+to_string((x)&255)+"/"+to_string(32-(int)log2(step));
        res.push_back(s);
        
    }
};