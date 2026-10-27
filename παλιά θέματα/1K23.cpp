#include <iostream>
#include <stdexcept>
using namespace std;

class my_vector {
    private:
    int size;
    int *vec;

    public:
    my_vector(int x, int val = 0) {
        size = x;
        vec = new int[size];
        for (int i = 0; i < size; ++i) {
            vec[i] = val;
        }
    }

    my_vector(const my_vector &v) {
        size = v.size;
        vec = new int [size];
        for (int i = 0; i < v.size; ++i) {
            vec[i] = v.vec[i];
        }
    }
    
    ~my_vector() {
        delete [] vec;
    }

    my_vector operator+ (const my_vector &vec2) {
        if (size != vec2.size) throw logic_error("they not the same size!");
        my_vector nvec(size);
        for (int i = 0; i < size; ++i) {
            nvec[i] = vec[i] + vec2.vec[i];
        }
        return nvec;
    }

    int& operator[] (int k)  {
        if (k < 0 || k >= size) throw logic_error("out of range");
        return vec[k];
    }

    friend ostream& operator<< (ostream &out, const my_vector &v);

    my_vector& operator= (const my_vector &v) {
        if (this == &v) return *this;
        size = v.size;
        delete []vec;
        vec = new int[size];
        for (int i = 0; i < v.size; ++i) {
            vec[i] = v.vec[i];
        }
        return *this;
    }
};


ostream& operator<< (ostream &out, const my_vector &v) {
    for (int i = 0; i < v.size; ++i) {
        out << v.vec[i];
    }
    return out;
}

