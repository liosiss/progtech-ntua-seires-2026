
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

struct Entry {
    int id;
    string fname, lname;
    int year;
    int salary;
};

struct Query {
    string category;
    string order;
    int limit;
};

void print(const Entry& e) {
    cout << e.id << " "
         << e.fname << " "
         << e.lname << " "
         << e.year << " "
         << e.salary << '\n';
}

int main() {

    int n;
    cin >> n;

    vector<Entry> db(n);

    for (int i = 0; i < n; i++) {
        cin >> db[i].id
            >> db[i].fname
            >> db[i].lname
            >> db[i].year
            >> db[i].salary;
    }

    int q;
    cin >> q;

    while (q--) {

        string category, order;
        int limit;

        cin >> category >> order >> limit;

        vector<Entry> temp = db;

        // SORTING RULE
        if (category == "id") {

            sort(temp.begin(), temp.end(),
                [](const Entry& a, const Entry& b) {
                    return a.id < b.id;
                });

        } else if (category == "name") {

            sort(temp.begin(), temp.end(),
                [](const Entry& a, const Entry& b) {

                    if (a.fname != b.fname)
                        return a.fname < b.fname;

                    return a.lname < b.lname;
                });

        } else if (category == "year") {

            sort(temp.begin(), temp.end(),
                [](const Entry& a, const Entry& b) {
                    return a.year < b.year;
                });

        } else if (category == "salary") {

            sort(temp.begin(), temp.end(),
                [](const Entry& a, const Entry& b) {
                    return a.salary < b.salary;
                });
        }

        // DESCENDING
        if (order == "desc") {
            reverse(temp.begin(), temp.end());
        }

        cout << "Query: "
             << category << " "
             << order << " "
             << limit << '\n';

        int cnt = min(limit, (int)temp.size());

        for (int i = 0; i < cnt; i++) {
            print(temp[i]);
        }
    }

    return 0;
}