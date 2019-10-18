class ZeroEvenOdd {
private:
    int n;

public:
    ZeroEvenOdd(int n) {
        this->n = n;
    }

    // printNumber(x) outputs "x", where x is an integer.
    void zero(function<void(int)> printNumber) {
        // ??????while????ThreadA????zero??
        while(1){
            {
                unique_lock<mutex> lk(_mu);
                _cond.wait(lk,[this](){return print0;});
                if(i<=n) printNumber(0);
                print0=printodd=printeven=false;
                if(i%2==1) printodd=true;
                else printeven=true;
            }
            
            _cond.notify_all();
            if(i>n) break;
        }
        
    }

    // ??
    void even(function<void(int)> printNumber) {
        while(1){
            {
                unique_lock<mutex> lk(_mu);
                _cond.wait(lk,[this](){return printeven;});
                if(i<=n) printNumber(i++);
                print0=true;
                printodd=printeven=false;
            }
            
            _cond.notify_all();
            if(i>n) break;
        }
        
    }

    // ??
    void odd(function<void(int)> printNumber) {
        while(1){
            {
                unique_lock<mutex> lk(_mu);
                _cond.wait(lk,[this](){return printodd;});
                if(i<=n) printNumber(i++);
                print0=true;
                printodd=printeven=false;
            }
            
            _cond.notify_all();
            if(i>n) break;
        }
        
    }
    
    
    mutex _mu;
    condition_variable _cond;
    int i=1;
    bool print0=true,printeven=false,printodd=false;
};