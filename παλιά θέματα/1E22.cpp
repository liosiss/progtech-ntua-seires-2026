#include <iostream>
using namespace std;

template <typename T>
class sorted_vector {
    private:
    T sum;
    int size;
    struct node {
        T x;
        node *next;
    };
    node *start;

    public:

    sorted_vector{
        size = 0;
        start = nullptr;
    }


    T getsum() {return sum;}
    int getsize() {return size;}
    bool empty() {return size == 0;}

    void add(T c) {
        if (start == nullptr) {
            sum = c;
            size++;
            node *q = new node;
            q->x = c;
            q->next = nullptr;
            start = q;
            return;
        }

        node *q = new node;
        q->x = c;
        q->next = nullptr;

    }
};
