class Solution {
 public:
  const double eps=1e-6;
  // https://www.cnblogs.com/grandyang/p/8395062.html
  bool judgePoint24(vector<int>& vec) {
    vector<double> nums(vec.begin(),vec.end()); // ???double??
    return dfs(nums);
  }

  bool dfs(vector<double>& nums) {
    if(nums.size()==1){
//      if(nums[0]!=24.000 && abs(24-nums[0])<=eps){
//        std::cout << std::setprecision(10)<<abs(24-nums[0])<<endl;
//      }
      // ??????????,?????????
      // ??????????????????????????p/q==1/3?
      if(abs(24-nums[0])<=eps){
        cout<<nums[0]<<endl;
        return true;
      }
      return false;
    }
      
    for(int i=0;i<nums.size();i++){
      for(int j=0;j<i;j++){ // ??j????i???????????erase???
        auto p=nums[i],q=nums[j]; // ???????????????????????
        vector<double> tmp={p+q,p-q,q-p,p*q};
        if(p>eps) tmp.push_back(q/p);
        if(q>eps) tmp.push_back(p/q);
        nums.erase(nums.begin()+i); // ??erase i
        nums.erase(nums.begin()+j);
        for(const auto &d:tmp){
          nums.push_back(d);
          if(dfs(nums)) return true;
          nums.pop_back();
        }
        nums.insert(nums.begin()+j,q); // ??insert j
        nums.insert(nums.begin()+i,p);
      }
    }
    return false;
  }

};