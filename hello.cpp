#include <iostream>
#include <ctime>
#include <exception>

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

    int *p = new int[5];

    for (int i=0; i<5; i++) {
        p[i] = i;
    }

    delete []p;
    cout << p << endl;
    cout << *p << endl;
    p=NULL;
    
    try {
        if (p==NULL) {
            cout << "after throw\n";
        }
        else {
            cout << p << endl;
            cout << *p << endl;
        }
    }
    catch (runtime_error &e){
        cout << e.what() << endl;
    }

    cout << "hello, world\n";
    string str;
    getline(cin, str, ',');

    return 0;
}