class Solution {
public:
    string dayOfTheWeek(int day, int month, int year) {
        unordered_map<int,string> um={{1,"Monday"},{2,"Tuesday"},{3,"Wednesday"},{4,"Thursday"},{5,"Friday"},{6,"Saturday"},{0,"Sunday"}};
        int t=dayofweek(day,month,year);
        cout<<t<<endl;
        return um[t];
    }
    
    int dayofweek(int d, int m, int y)  
    {  
        static int t[] = { 0, 3, 2, 5, 0, 3, 
                       5, 1, 4, 6, 2, 4 };  
        y -= m < 3;  
        return ( y + y / 4 - y / 100 +  
             y / 400 + t[m - 1] + d) % 7;  
    } 
};