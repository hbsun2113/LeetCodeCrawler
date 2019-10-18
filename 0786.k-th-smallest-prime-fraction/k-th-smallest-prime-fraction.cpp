class Solution {
public:
    // https://www.cnblogs.com/grandyang/p/9135156.html
    
    // ????????????????????????(???????yxc???)
    vector<int> kthSmallestPrimeFraction(vector<int>& A, int K) {
        double l=0,r=1;
        int n=A.size();
        int p,q;
        while(1){
            double mid=(l+r)/2.0000;
            int cnt=0; // ??????mid???
            p=0,q=1;
            for(int i=0,j=0;i<n;i++){
                while(j<n && A[i]>mid*A[j]) j++;
                cnt+=(n-j);
                // ???A[i]/A[j]????????mid???
                if(j<n && p*A[j]<q*A[i])  // p/q < A[i]/A[j]??????????(A[i]/A[j]),??????mid
                    p=A[i],q=A[j];
            }
            if(cnt==K) return {p,q}; // ??????(A[i]/A[j])??????K?
            if(cnt>K) r=mid;
            else l=mid;
            // cout<<mid<<" "<<cnt<<" "<<l<<" "<<r<<endl;
        }
        return {INT_MIN,INT_MAX};
    }
    
    
    // ??????????
    vector<int> kthSmallestPrimeFraction1(vector<int>& A, int K) {
        // {?,{?????????}}
        priority_queue<pair<double,pair<int,int>>, vector<pair<double,pair<int,int>>>, greater<pair<double,pair<int,int>>>> q;
        for(int i=0;i<A.size();i++){
            q.push({double(A[i])/A.back(),{i,A.size()-1}});
        }
        while(--K){
            auto t=q.top().second;
            q.pop();
            t.second--;
            q.push({double(A[t.first])/A[t.second],{t.first,t.second}});
        }
        return {A[q.top().second.first],A[q.top().second.second]};
    }
};