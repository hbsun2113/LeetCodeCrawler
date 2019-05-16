class Solution {
public:
    string countAndSay(int n) {
        string last="1";
        for(int i=1;i<n;i++){
            string tmp="";
            int count=0;
            for(int j=0;j<last.size();j++){
                count++;
                if(j==last.size()-1 || last[j]!=last[j+1]){
                    tmp+=to_string(count);
                    tmp+=last[j];
                    count=0;
                }
            }
            cout<<i<<" "<<tmp<<endl; 
            last=tmp;
        }
        return last;
        
    }
    
    
    vector<string> res;
    string countAndSay1(int n) {
        res.push_back("1");
        res.push_back("11");
        res.push_back("21");
        res.push_back("1211");
        res.push_back("111221");
        for(int i=5;i<n;i++){
            string tmp="";
            string pre=res[i-1];
            int count=1;
            char c=pre[0];
            for(int i=1;i<pre.size();i++){
                if(pre[i]==c){
                    count++;
                    continue;
                }
                else{
                    tmp+=to_string(count);
                    tmp+=c;
                    count=1;
                }
                c=pre[i];
            }
            tmp+=to_string(count);
            tmp+=c;
            res.push_back(tmp);
        }
        return res[n-1];
        
        
        
    }
};