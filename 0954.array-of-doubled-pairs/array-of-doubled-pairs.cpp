class Solution {
public:
    
    //暴力解法，不可取！
    
    /*static bool comp(int a,int b){
        return abs(a)<abs(b);
    }
    
    bool canReorderDoubled(vector<int>& A) {
        unordered_map<int,int> um;
        for(const auto &a:A){
            um[a]++;
        }
        sort(A.begin(),A.end(),comp);
        //for(const auto &a:A) cout<<a<<" ";
        //cout<<endl;
        int index=0;
        while(!um.empty() && index<A.size()){
            int value=A[index];
            int target=2*value;
            if(!um[target] || (um[target]<um[value])){
                cout<<value<<" "<<target<<" "<<um[value]<<" "<<um[target]<<endl;
                return false;
            }
            else{
                int count=um[value];
                um.erase(value);
                um[target]-=count;
                if(um[target]<=0) um.erase(target);
            }
            while(um.count(A[index])==0 && index<A.size()){
                //cout<<index<<" "<<A[index]<<endl;
                index++;
            }
            //cout<<um.size()<<endl;
        }
        return true;
        
    }*/
    
    
    //看了其他答案，似乎思路和我上面的解法一样，重写一版，主要是为了简化
    bool canReorderDoubled(vector<int>& A) {
        unordered_map<int,int> um;
        vector<int> unique_set;
        
        for(const auto &a:A) um[a]++;
        for(const auto &u:um) unique_set.push_back(u.first);
        
        auto cmp=[](int a,int b){ return abs(a)<abs(b);};
        sort(unique_set.begin(),unique_set.end(),cmp);
        
        for(const auto &a:unique_set){
            if(um[a]>um[2*a]) return false;
            um[2*a]-=um[a];
        }
        
        return true;
    }
};