class Solution {
public:
    int bitwiseComplement(int N) {
        if(N==0) return 1;
        if(N==1) return 0;
        vector<int> vec;
        bool flag=true;
        int pos;
        int i=0;
        while(N>0){
            int tmp=1-N%2;
            N/=2;
            vec.push_back(tmp);
            if(tmp==1) pos=i;
            i++;
        }
        vec.resize(pos+1);
        // for(const auto &v:vec)
        //     cout<<v<<" ";
        // cout<<endl;
        long long res=0;
        int base=1;
        for(int i=0;i<vec.size();i++){
            res+=vec[i]*base;
            base*=2;
        }
        return res;
        
    }
};