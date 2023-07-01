//https://leetcode.com/problems/print-foobar-alternately/description/
class FooBar {
private:
    int n;
    bool fooTime = true;
    condition_variable cv;
    mutex m;

public:
    FooBar(int n) {
        this->n = n;
    }

    void foo(function<void()> printFoo) {
        
        for (int i = 0; i < n; i++) {
            
        	// printFoo() outputs "foo". Do not change or remove this line.
            unique_lock lk(m);
            cv.wait(lk, [this]{return fooTime;});
        	printFoo();
            fooTime = !fooTime;
            lk.unlock();
            cv.notify_one();
        }
    }

    void bar(function<void()> printBar) {
        
        for (int i = 0; i < n; i++) {
            
        	// printBar() outputs "bar". Do not change or remove this line.
            unique_lock lk(m);
            cv.wait(lk, [this]{return !fooTime;});
        	printBar();
            fooTime = !fooTime;
            lk.unlock();
            cv.notify_one();
        }
    }
};
