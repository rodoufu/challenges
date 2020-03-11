// https://leetcode.com/problems/print-foobar-alternately/
class FooBar {
private:
    int n;
    mutex m1, m2;

public:
    FooBar(int n) {
        this->n = n;
    }

    void foo(function<void()> printFoo) {
        for (int i = 0; i < n; i++) {
            m1.lock();
        	printFoo();
            m2.unlock();
        }
    }

    void bar(function<void()> printBar) {        
        for (int i = 0; i < n; i++) {
            m2.lock();
        	printBar();
            m1.unlock();
        }
    }
};
