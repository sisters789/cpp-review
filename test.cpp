#include <iostream>
#include <string>
#include <exception>

using namespace std;

template<class T>
struct node{
    T value;
    node<T>* next;
};

template<class T>
class linkList {
    protected:
        node<T>* head;
        int size;

        node<T>* newNode(T value) {
            node<T> *p = new node<T>;
            p->value = value;
            p->next = NULL;
            return p;
        }
    public:
        linkList() {
            head = NULL; size = 0;
        }

        int addHead(T value) {
            try {
                node<T>* p = newNode(value);

                if (head==NULL) {
                    head = p;
                }
                else {
                    p->next = head;
                    head = p;
                }
                size++;
                return 0;
            }
            catch (runtime_error &e) {
                cerr << e.what() << endl;
                return 1;
            }
        }

        T at(int index) {
            try {
                if (index>=size || index<0) {
                    throw("out of range");
                }

                int i=0;
                node<T>* p = head;
                while(p!=NULL) {
                    if (i==index) {
                        return p->value;
                    }
                    i++;
                    p = p->next;
                }
            }
            catch (const char* msg) {cerr << msg << endl;}
        }

        ~linkList() {
            while(head!=NULL) {
                node<T>* p = head;
                head = head->next;
                delete p;
            }
            head = NULL;
        }
};

template<class T>
class Stack: protected linkList<T> {
    public:
        T top() {
            node<T>* p = linkList<T>::head;
            return p->value;
        }
        T pop() {
            node<T>* p = linkList<T>::head;
            T value = p->value;
            linkList<T>::head = p->next;
            delete p;

            return value;
        }
        int push(const int &value) {
            this->addHead(value);
            return 0;
        }
};

int main()
{
    linkList<int> list;
    for(int i=0; i<7; i++) {
        list.addHead(i);
    }
    
    cout << list.at(10) << endl;

    // Stack<int> s;
    // for(int i=0; i<7; i++) {
    //     s.push(i);
    // }
    // cout << s.top() << endl;
    // cout << s.pop() << endl;
    // cout << s.top() << endl;
    // cout << s.pop() << endl;

    cout << "END" << endl;
    return 0;
}