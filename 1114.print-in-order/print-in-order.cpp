class Foo {
public:
    Foo() {
        
    }

    void first(function<void()> printFirst) {
        // cout<<1<<endl;
        // printFirst() outputs "first". Do not change or remove this line.
        // mtx.lock();
        printFirst();
        flag=1;
        // mtx.unlock();
        cond.notify_all();
        // cout<<11<<endl;
    }

    void second(function<void()> printSecond) {
        // cout<<2<<endl;
        {
            unique_lock<mutex> lk(mtx);
            cond.wait(lk,[this](){return flag==1;});
            // printSecond() outputs "second". Do not change or remove this line.
            printSecond();
            flag=2;
        }
        
        // cout<<22<<endl;
        cond.notify_all();
    }

    void third(function<void()> printThird) {
        // cout<<3<<endl;
        unique_lock<mutex> lk(mtx);
        cond.wait(lk,[this](){return flag==2;});
        // printThird() outputs "third". Do not change or remove this line.
        printThird();
        flag=3;
        // cout<<33<<endl;
    }
    
    mutex mtx;
    condition_variable cond;
    int flag=0;
};