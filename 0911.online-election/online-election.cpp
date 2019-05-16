class TopVotedCandidate {
public:
    //自己没有做出来，参照https://leetcode.com/problems/online-election/discuss/173382/C++JavaPython-Binary-Search-in-Times，主要是要读懂题目
    map<int, int> m; //time->person
    TopVotedCandidate(vector<int> persons, vector<int> times) { //注意时间是递增的
        if(!std::is_sorted(times.begin(), times.end())) 
           return ;
        int n = persons.size(), lead = -1;
        unordered_map<int, int> count; // person->count
        for (int i = 0; i < n; ++i) m[times[i]] = persons[i];
        for (auto it : m) {
            if (++count[it.second] >= count[lead])lead = it.second;
            m[it.first] = lead;
        }
    }

    int q(int t) {
        return (--m.upper_bound(t))-> second;
    }
    
    
};

/**
 * Your TopVotedCandidate object will be instantiated and called as such:
 * TopVotedCandidate obj = new TopVotedCandidate(persons, times);
 * int param_1 = obj.q(t);
 */