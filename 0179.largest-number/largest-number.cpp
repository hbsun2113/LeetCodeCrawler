class Solution {
public:
    //自己的解法出现了不可解释的错误，先使用discuss里的思路。
   /*bool vcmp(const vector<int> &va,const vector<int> &vb){
       int ia=va.size()-1,ib=vb.size()-1;
       cout<<"ia:"<<ia<<" "<<"ib:"<<ib<<endl;
       while(ia>=0 && ib>=0){
           cout<<ia<<" "<<ib<<endl;
           if(va[ia]<vb[ib]) return true;
           if(va[ia]>vb[ib]) return false;
           ia--,ib--;
       }
       if(ia<0) return false;
       return true;
   }
       
    
    
    string largestNumber(vector<int>& nums) {
        // sort(nums.begin(),nums.end());
        // if(nums[nums.size()-1]==0) {
        //     cout<<nums[0]<<" "<<nums[nums.size()-1]<<endl;
        //     return string("0");
        // }
        auto cmp=[this](const int &a,const int &b){
            vector<int> aa;
            vector<int> bb;
            int tmpa=a,tmpb=b;
            while(tmpa>0 || tmpb>0){
                if(tmpa>0){
                    aa.emplace_back(tmpa%10);
                    tmpa/=10;
                }
                if(tmpb>0){
                    bb.emplace_back(tmpb%10);
                    tmpb/=10;
                }
                //cout<<a<<" "<<b<<endl;
                
            }
            //if(tmpa==0 && tmpb==0) cout<<aa.size()<<bb.size()<<endl;
            //cout<<tmpa<<" "<<tmpb<<"--";
            //cout<<aa.size()<<" "<<bb.size()<<"--";
            //bool flag=vcmp(aa,bb);
            //cout<<"flag="<<flag<<" ";
            return vcmp(aa,bb);
        };
        
        //cout<<"sort begin and nums.size()="<<nums.size()<<endl;
        sort(nums.begin(),nums.end(),cmp);
        //cout<<"sort finish and nums.size()="<<nums.size()<<endl;
        string result="";
        for(int i=nums.size()-1;i>=0;i--){
            cout<<nums[i]<<" ";
            result+=to_string(nums[i]);
        }
        return result;
    }*/
    
    
    
    
    string largestNumber(vector<int>& nums) {
        if(*std::max_element(begin(nums), end(nums))==0) return "0";
        auto cmp=[](int a,int b){
            return to_string(a)+to_string(b)>to_string(b)+to_string(a);
        };
        sort(nums.begin(),nums.end(),cmp);
        string result="";
        for(const auto &num:nums)
            result+=to_string(num);
        return result;
        
    }
    
    
    
    
    
    
};