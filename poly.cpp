#include <iostream>
#include <fstream>
#include <cmath>
#include <stack>
#include <map>
using namespace std;

class shape {
    public:
        shape(){}
        ~shape(){}
        virtual float area() {
            return 0;
        }
};

class rectangle : public shape {
    private:
        float width;
        float height;
    public:
        rectangle(){}
        rectangle(float w, float h):width(w), height(h){}
        float area() override
        {
            return width*height;
        }

        ~rectangle(){}
};

class triangle : public shape {
    private:
        float a, b, c;
    public:
        triangle(){}
        triangle(float a, float b, float c):a(a), b(b), c(c){}
        float area() override
        {
            float p = (a+b+c)/2;
            return sqrt(p*(p-a)*(p-b)*(p-c));
        }
        
        ~triangle(){}
};

double division(int a, int b) {
   if( b == 0 ) {
      throw "Division by zero condition!";
   }
   return (a/b);
}

int main() {

    rectangle rect(10, 20);
    triangle tri(3,4,5);

    shape* p = new shape();
    cout << p->area() << endl;
    delete p;

    p=&rect;
    cout << p->area() << endl;
    
    p=&tri;
    cout << p->area() << endl;

    return 0;
}