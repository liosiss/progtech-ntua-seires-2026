#include <iostream>
#include <cmath>
using namespace std;

class Polynomial {
protected:
    class Term {
    protected:
        int exponent;
        int coefficient;
        Term *next;

        Term(int exp, int coeff, Term *n)
            : exponent(exp), coefficient(coeff), next(n) {}

    public:
        friend class Polynomial;
        friend Polynomial operator+(const Polynomial &, const Polynomial &);
        friend Polynomial operator*(const Polynomial &, const Polynomial &);
        friend ostream &operator<<(ostream &, const Polynomial &);
    };

    void push(const int &e, const int &c) {
        Term *v = new Term(e, c, nullptr);

        if (start == nullptr) {
            start = v;
            return;
        }

        Term *q = start;
        while (q->next != nullptr) {
            q = q->next;
        }
        q->next = v;
    }

public:
    Polynomial() : start(nullptr) {}

    Polynomial(const Polynomial &p) : start(nullptr) {
        for (Term *i = p.start; i != nullptr; i = i->next) {
            push(i->exponent, i->coefficient);
        }
    }

    ~Polynomial() {
        while (start != nullptr) {
            Term *q = start;
            start = start->next;
            delete q;
        }
    }

    Polynomial &operator=(const Polynomial &p) {
        if (this == &p) return *this;

        Term *v = start;
        while (v != nullptr) {
            Term *q = v;
            v = v->next;
            delete q;
        }

        start = nullptr;

        
        for (Term *i = p.start; i != nullptr; i = i->next) {
            push(i->exponent, i->coefficient);
        }

        return *this;
    }

    void addTerm(int expon, int coeff) {
        if (coeff == 0) return;

        if (start == nullptr || expon > start->exponent) {
            start = new Term(expon, coeff, start);
            return;
        }

        Term *q = start;

        while (q->next != nullptr && expon < q->next->exponent) {
            q = q->next;
        }

        if (q->next != nullptr && q->next->exponent == expon) {
            q->next->coefficient += coeff;
        }
        else if (q->exponent == expon) {
            q->coefficient += coeff;
        }
        else {
            q->next = new Term(expon, coeff, q->next);
        }
    }

    double evaluate(double x) {
        double res = 0;

        for (Term *q = start; q != nullptr; q = q->next) {
            res += q->coefficient * pow(x, q->exponent);
        }

        return res;
    }

    friend Polynomial operator+(const Polynomial &p, const Polynomial &q) {
        Term *ptr1 = p.start;
        Term *ptr2 = q.start;
        Polynomial res;

        while (ptr1 != nullptr && ptr2 != nullptr) {
            if (ptr1->exponent == ptr2->exponent) {
                res.push(ptr1->exponent,
                         ptr1->coefficient + ptr2->coefficient);
                ptr1 = ptr1->next;
                ptr2 = ptr2->next;
            }
            else if (ptr1->exponent > ptr2->exponent) {
                res.push(ptr1->exponent, ptr1->coefficient);
                ptr1 = ptr1->next;
            }
            else {
                res.push(ptr2->exponent, ptr2->coefficient);
                ptr2 = ptr2->next;
            }
        }

        while (ptr1 != nullptr) {
            res.push(ptr1->exponent, ptr1->coefficient);
            ptr1 = ptr1->next;
        }

        while (ptr2 != nullptr) {
            res.push(ptr2->exponent, ptr2->coefficient);
            ptr2 = ptr2->next;
        }

        return res;
    }

    friend Polynomial operator*(const Polynomial &p, const Polynomial &q) {
        Polynomial result;

        for (Term *i = p.start; i != nullptr; i = i->next) {
            for (Term *j = q.start; j != nullptr; j = j->next) {
                result.addTerm(
                    i->exponent + j->exponent,
                    i->coefficient * j->coefficient);
            }
        }

        return result;
    }

    friend ostream &operator<<(ostream &out, const Polynomial &p) {
    Term *q = p.start;
    bool firstPrinted = false;

    while (q != nullptr) {
        if (q->coefficient != 0) {   

            if (firstPrinted) {
                if (q->coefficient < 0) out << " - ";
                else out << " + ";
            } else {
                if (q->coefficient < 0) out << "-";
                firstPrinted = true;
            }

            int absCoeff = abs(q->coefficient);

            if (q->exponent == 0) {
                out << absCoeff;
            }
            else if (q->exponent == 1) {
                if (absCoeff != 1) out << absCoeff;
                out << "x";
            }
            else {
                if (absCoeff != 1) out << absCoeff;
                out << "x^" << q->exponent;
            }
        }

        q = q->next;
    }

    
    if (!firstPrinted) {
        out << 0;
    }

    return out;
}
private:
    Term *start;
};

int main() {
  Polynomial p;
  p.addTerm(1, 3);
  p.addTerm(2, 1);
  p.addTerm(0, -1);
  Polynomial q(p);
  q.addTerm(1, -3);
  
  cout << "P(X) = " << p << endl;
  cout << "P(1) = " << p.evaluate(1) << endl;
  cout << "Q(X) = " << q << endl;
  cout << "Q(1) = " << q.evaluate(1) << endl;
  cout << "(P+Q)(X) = " << p+q << endl;
  return 0;
}


