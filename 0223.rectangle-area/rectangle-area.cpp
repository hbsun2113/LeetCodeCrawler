class Solution {
public:
    int computeArea(int A, int B, int C, int D, int E, int F, int G, int H) {
        long long area1=(C-A)*(D-B);
        long long area2=(G-E)*(H-F);
        
        long long len1=(long long)min(C,G)-max(A,E);
        long long len2=(long long)min(D,H)-max(B,F);
        long long area3=max(0ll,len1)*max(0ll,len2);
        
        return area1-area3+area2;
    }
};