#include <iostream>
using namespace std;

template <typename T>
class stack{

    public:

    stack(int size){
        s=size;
        a= new T[size];
    }

    stack(const stack &x){
        s=x.s;
        e=x.e;
        a=new T[s];
        for( int i=0; i<=e; i++) a[i]=x.a[i];
    }

    ~stack(){
        delete [] a;
    }

    bool empty(){
        return e==-1;
    }

    void push(const T &x){
        a[++e]=x;
    }

    int pop(){
        return a[e--];
    }

    int size() {
        return e+1;
    }


    const stack & operator = (const stack &c) {
        if (this == &c) return *this;

        delete [] a;
        s=c.s;
        e=c.e;
        a=new T[s];
        for(int i=0; i<=e; i++) a[i]=c.a[i];
        return *this;
    }
    
    friend ostream & operator << (ostream &out, const stack &s){
      out << "[";
      for (int i = 0; i <= s.e; i++) {
        out << s.a[i];
        if (i < s.e)
            out << ",";
      }
      out << "]";
      return out;
    };

    private:

    int s; //size
    int e=-1; //top
    T *a; //pointer: points to array 

};


#ifndef CONTEST
 int main () {
 
stack<int> s(10);
cout <<"s is empty:" << s << endl;
 s.push(42);
 cout <<"s has one element:" << s << endl;
 s.push(17);
 s.push(34);
 cout <<"s has more elements:" << s << endl;
 cout <<"How many? " << s.size() << endl;
 stack<int> t(5);
 t.push(7);
 cout <<"t:" << t << endl;
 t = s;
 cout << "popping from s: " << s.pop() << endl;

 s.push(8);
 stack<int> a(s);
 t.push(99);
 a.push(77);
 cout <<"s:" << s << endl;
 cout <<"t:" << t << endl;
 cout <<"a:" << a << endl;

 stack<double> c(4);
 c.push(3.14);
 c.push(1.414);
 cout << "c contains doubles" << c << endl;
 
 stack<char> k(4);
 k.push('$');
 cout <<"k contains a character " << k << endl;
 
 return 0; 
}
 #endif