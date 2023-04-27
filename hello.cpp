#include <iostream>
#include <ctime>
using namespace std;
class B;
using namespace std;
class A {
    private:
        int a;
        void f1();
    friend class B;
};

class B {
    A var;
    void func() {};
};

int main() {

    
    return 0;
}