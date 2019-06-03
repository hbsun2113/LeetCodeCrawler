/**
 * // This is the Master's API interface.
 * // You should not implement it, or speculate about its implementation
 * class Master {
 *   public:
 *     int guess(string word);
 * };
 */
class Solution {
public:
    int match(string a, string b) {
        int matches = 0;
        for (int i = 0; i < a.length(); ++i) if (a[i] == b[i]) matches ++;
        return matches;
    }
    
    void findSecretWord(vector<string>& wordlist, Master& master) {
        for (int i = 0, x = 0; i < 10 && x < 6; ++i) {
            string guess = wordlist[i % wordlist.size()];
            x = master.guess(guess);
            vector<string> wordlist2;
            for (string w : wordlist)
                if (match(guess, w) == x)
                    wordlist2.push_back(w);
            cout<<i<<" "<<guess<<" "<<x<<" "<<wordlist2.size()<<endl;
            wordlist = wordlist2;
        }
    }
    
    int check(string &a, string &b){
        int res=0;
        for(int i=0;i<a.size();i++)
            res+=(a[i]==b[i]);
        return res;
    }
    
    
    
    vector<bool> vis;
    int count;
    vector<unordered_map<int,vector<int>>> um;
    unordered_map<int,int> record;
    void findSecretWord2(vector<string>& wordlist, Master& master) {
        vis.clear();
        vis.resize(wordlist.size(),false);
        um.resize(wordlist.size());
        int seed=0;
        int samecount=0;
        for(int i=0;i<wordlist.size();i++){
            for(int j=i+1;j<wordlist.size();j++){
                string &a=wordlist[i];
                string &b=wordlist[j];
                int same=check(a,b);
                um[i][same].push_back(j);
                um[j][same].push_back(i);    
                if(um[i][same].size()>samecount){
                    samecount=um[i][same].size();
                    seed=i;
                }
                if(um[j][same].size()>samecount){
                    samecount=um[j][same].size();
                    seed=j;
                }
            }
        }
        seed=rand()%wordlist.size();
        cout<<wordlist[seed]<<endl;
        int same=master.guess(wordlist[seed]);
        record[seed]=same;
        count=1;
        vis[seed]=true;
        dfs(wordlist,master,seed,same,0);
    }
    
    void dfs(vector<string>& wordlist, Master& master, int seed, int same, int layer){
        layer++;
        if(count>=10) return ;
        cout<<layer<<" "<<um[seed][same].size()<<endl;
        for(auto w:um[seed][same]){
            w=um[seed][same][rand()%um[seed][same].size()];
            // if(vis[w]) continue;
            
            // for(const auto &r:record){
                // if(check(wordlist[w],wordlist[r.first])==r.second) {
                    int new_same=master.guess(wordlist[w]);
                    record[w]=new_same;
                    count++;
                    if(count>=10) return;
                    cout<<layer<<" | "<<wordlist[w]<<" "<<new_same<<" "<<same<<endl;
                    // vis[w]=true;
                    // if(new_same<same) continue;
                    dfs(wordlist,master,w,new_same,layer);
                // }
            // }
            
        }
    }
};