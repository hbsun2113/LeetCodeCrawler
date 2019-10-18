class Solution {
public:
    int dayOfYear(string date) {
        // if(data.size()==0) return 0;
        int year,month,day;
        istringstream ins(date);
        getline(ins,date,'-');
        year=stoi(date);
        getline(ins,date,'-');
        month=stoi(date);
        getline(ins,date,'-');
        day=stoi(date);
        cout<<year<<" "<<month<<" "<<day<<endl;
        vector<int> m={31,28,31,30,31,30,31,31,30,31,30,31};
        if(addone(year)) m[1]++;
        int i=0;
        int res=0;
        while(i<month-1) res+=m[i++];
        res+=day;
        return res;
    }
    
    bool addone(int year){
        if(year%4!=0) return false;
        if(year % 100 == 0 && year % 400 != 0) return false;
        return true;
    }
    
    
};