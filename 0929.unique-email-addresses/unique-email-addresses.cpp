class Solution {
public:
    int numUniqueEmails(vector<string>& emails) {
        unordered_set<string> us;
        for(const auto &e:emails){
            int pos=e.find_last_of('@');
            string local=e.substr(0,pos);
            string domain=e.substr(pos);
            // cout<<e<<":"<<local+domain<<endl;
            int i=0;
            string tmp="";
            while(i<local.size() && local[i]!='+'){
                if(local[i]=='.'){
                    i++;
                    continue;
                }
                tmp+=local[i++];
            }
            us.emplace(tmp+domain);
        }
        return us.size();
    }
};