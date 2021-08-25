class Foo {
public:
    vector<bool> check;
    Foo() {
        check = {false, false};
    }

    void first(function<void()> printFirst) {
        
        // printFirst() outputs "first". Do not change or remove this line.
        printFirst();
        check[0] = true;
    }

    void second(function<void()> printSecond) {
        while(!check[0]) {}
        
        // printSecond() outputs "second". Do not change or remove this line.
        printSecond();
        check[1] = true;
    }

    void third(function<void()> printThird) {
        while(!check[1]) {}
        
        // printThird() outputs "third". Do not change or remove this line.
        printThird();
    }
};