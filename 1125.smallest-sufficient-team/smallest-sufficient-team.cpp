class Solution {
public:
    // https://leetcode.com/problems/smallest-sufficient-team/discuss/334832/c++-dp-bitmask-solution-with-algorithm
    vector<int> smallestSufficientTeam(vector<string>& req_skills, vector<vector<string>>& people) {
        int n=req_skills.size();
        unordered_map<string,int> um;
        for(int i=0;i<n;i++) um[req_skills[i]]=i;
        map<int,vector<int>> res; // ???????unordered_map?https://leetcode.com/problems/smallest-sufficient-team/discuss/334832/c++-dp-bitmask-solution-with-algorithm???
        res[0]={};
        for(int i=0;i<people.size();i++){
            int cur_skill=0;
            for(const auto &s:people[i]) cur_skill |= (1<<(um[s]));
            
            for(const auto &r:res){ // ?????????
                int cmb_skill = (r.first | cur_skill);
                if(res.find(cmb_skill)==res.end() || res[cmb_skill].size()>1+res[r.first].size()){
                    res[cmb_skill]=r.second;
                    res[cmb_skill].push_back(i);
                    cout<<cmb_skill<<" "<<res[cmb_skill].size()<<endl;
                }
            } 
        }
        return res[(1<<n)-1];
        
            
    }
};