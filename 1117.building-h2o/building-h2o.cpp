class H2O {
public:
    H2O() {
        
    }

    void hydrogen(function<void()> releaseHydrogen) {
        
        // releaseHydrogen() outputs "H". Do not change or remove this line.
        unique_lock<mutex> lk(_mtx);
        _cond.wait(lk,[this](){return h>0;});
        releaseHydrogen();
        h--;
        if(h==0 && o==0){
            h=2,o=1;
        }
        _cond.notify_one();
    }

    void oxygen(function<void()> releaseOxygen) {
        
        // releaseOxygen() outputs "O". Do not change or remove this line.
        unique_lock<mutex> lk(_mtx);
        _cond.wait(lk,[this](){return o>0;});
        releaseOxygen();
        o--;
        if(h==0 && o==0){
            h=2,o=1;
        }
        _cond.notify_one();
    }

    mutex _mtx;
    condition_variable _cond;
    int h=2,o=1;
};