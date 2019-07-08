class Solution {
public:
    string minimizeError(vector<string>& prices, int target, int res = 0) {
        vector<short> ds;
        for (auto pr : prices) {
            int i_pr = round(stof(pr) * 1000);
            target -= i_pr / 1000;
            if (i_pr % 1000) ds.push_back(i_pr % 1000);
        }
        if (target < 0 || target > ds.size()) return "-1";
        nth_element(begin(ds), begin(ds) + ds.size() - target, end(ds));
        for (auto d : ds) res += ds.size() > target++ ? d : 1000 - d;
        return to_string(res / 1000) + "." + string(3 - to_string(res % 1000).size(), '0') + to_string(res % 1000);
    }
};