class Solution {
public:
    vector<string> fizzBuzz(int n) {
        vector<string> result;
        for(int i=1;i<=n;i++){
            if(i%3==0){
                if(i%5==0){
                    result.emplace_back("FizzBuzz");
                }
                else result.emplace_back("Fizz");
            }
            else if(i%5==0) result.emplace_back("Buzz");
            else result.emplace_back(to_string(i));
        }
        return result;
    }
};