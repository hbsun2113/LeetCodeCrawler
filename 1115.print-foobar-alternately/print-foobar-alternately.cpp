class FooBar {
private:
    int n;

public:
    FooBar(int n) {
        this->n = n;
    }

    void foo(function<void()> printFoo) {
        
        for (int i = 0; i < n; i++) {
            {
                unique_lock<mutex> lk(mu_);
                cond_.wait(lk,[this](){return state==false;});
        	    // printFoo() outputs "foo". Do not change or remove this line.
        	    printFoo();
                state=true;
            }
            
            cond_.notify_one();
        }
    }

    void bar(function<void()> printBar) {
        
        for (int i = 0; i < n; i++) {
            {
                unique_lock<mutex> lk(mu_);
                cond_.wait(lk,[this](){return state==true;});
        	    // printBar() outputs "bar". Do not change or remove this line.
        	    printBar();
                state=false;
            }
            
            cond_.notify_one();
        }
    }
    
    mutex mu_;
    condition_variable cond_;
    bool state=false;
};