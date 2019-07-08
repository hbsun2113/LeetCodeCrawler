class Solution {
public:
    int slidingPuzzle(vector<vector<int>>& board) {
        string target="123450";
        string start="";
        for(int i=0;i<2;i++)
            for(int j=0;j<3;j++)
                start+=to_string(board[i][j]);
        if(start==target) return 0;
        // cout<<start<<endl;
        
        unordered_set<string> us;
        queue<string> q;
        q.push(start);
        vector<vector<int>> exchange{ {1,3}, {0,2,4}, {1,5}, {0,4}, {1,3,5}, {2,4} };
        
        int res=0;
        while(!q.empty()){
            int size=q.size();
            res++;
            for(int i=0;i<size;i++){
                auto t=q.front();
                q.pop();
                int index=t.find_first_of('0');
                for(const auto &p:exchange[index]){
                    string tmp=t;
                    swap(tmp[index],tmp[p]);
                    if(tmp==target) return res;
                    if(us.find(tmp)!=us.end()) continue;
                    q.push(tmp);
                    us.insert(tmp);
                }
            }
        }
        
        return -1;
    }
};