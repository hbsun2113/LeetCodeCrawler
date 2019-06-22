class Solution {
public:
    // 别弄反了就行
    vector<int> anagramMappings(vector<int>& A, vector<int>& B) {
        unordered_map<int,stack<int>> um;
        for(int i=0;i<B.size();i++){
            um[B[i]].push(i);
        }
        vector<int> res(B.size());
        for(int i=0;i<A.size();i++){
            res[i]=um[A[i]].top();
            um[A[i]].pop();
        }
        return res;
    }
};