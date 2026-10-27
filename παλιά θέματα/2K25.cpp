#include <iostream>
#include <set>
using namespace std;

class storage {
    private:
    multiset<double> st;

    public:

    storage();
    ~storage() {
        st.clear();
    }

    void add(const double &x) {
        st.insert(x);
        return;
    }

    double median() {
        int p;
        if (st.size() == 1) return st.first();
        if (st.size() % 2 == 0)
    }


};