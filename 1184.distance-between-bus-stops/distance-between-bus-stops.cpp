class Solution {
public:
    int distanceBetweenBusStops(vector<int>& distance, int start, int destination) {
        if(start==destination || distance.size()==0) return 0;
        int n=distance.size();
        int x=0,y=0;
        for(int i=start;i!=destination;i=(i+1)%n){
            x+=distance[i];
        }
        for(int i=destination;i!=start;i=(i+1)%n){
            y+=distance[i];
        }
        return min(x,y);
    }
};