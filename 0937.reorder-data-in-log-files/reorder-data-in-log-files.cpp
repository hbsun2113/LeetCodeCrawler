class Solution {
public:
    vector<string> reorderLogFiles(vector<string>& logs) {
        vector<string> digit,result;
        for(auto &n:logs){
            string id,first;
            istringstream ins(n);
            getline(ins,id,' ');
            getline(ins,first,' ');
            if(isdigit(first[0])) digit.push_back(n);
            else result.push_back(n);
        }
        
        auto cmp=[](string &a, string &b){
            string id1,content1,id2,content2;
            
            istringstream ins1(a);
            getline(ins1,id1,' ');
            getline(ins1,content1);
            
            istringstream ins2(b);
            getline(ins2,id2,' ');
            getline(ins2,content2);
            // cout<<content1<<" "<<content2<<endl;
            if(content1!=content2) return content1<content2;
            else return id1<id2;
        };
        
        sort(result.begin(),result.end(),cmp);
        for(const auto &n:digit) result.push_back(n);
        return result;
        
        
        
    }
};