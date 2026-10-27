// to exw kala sto grader edw to exw skatwsei
//sta lamda  functions gia to sort prepei na ftiaxtoun
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

struct entry {
    string fname, lname;
    int id, year, salary;
};

struct request {
    int times;
    string category, af;
};


void print_struct (const entry &i){
    cout << i.id << " " << i.fname << " " << i.lname << " " << i.year << " " << i.salary << '\n';
    return;
}

int main() {
    int n;
    cin >> n;
    vector<entry> temp(n);
    for (int i = 0; i < n; ++i) {
        cin >> temp[i].id >> temp[i].fname >> temp[i].lname >> temp[i].year >> temp[i].salary;
    }

    int k;
    cin >> k;
    vector<request> rq(k);
    for (int i = 0; i < k; ++i) {
        cin >> rq[i].category >> rq[i].af >> rq[i].times;
    } 

    for (const auto &q : rq){
        string change = q.af;
        if (q.category == "id"){
            sort(temp.begin(), temp.end(), [change](const entry &a, const entry &b){
                if(change == "desc") return a.id > b.id;
                return a.id < b.id;
            });
        }
        else if(q.category == "year"){
            sort(temp.begin(), temp.end(), [change](const entry &a, const entry &b){
                if(a.year != b.year){
                    if (change == "desc") return a.year > b.year;
                    return a.year < b.year;
                }
                if (change == "desc") return a.id > b.id;
                return a.id < b.id;
            });
        }
        else if(q.category == "salary"){
            sort(temp.begin(), temp.end(), [change](const entry &a, const entry &b){
                if(a.salary != b.salary) {
                    if (change == "desc")  return a.salary > b.salary;
                    return a.salary < b.salary;
                }
                if (change == "desc") return a.id > b.id;
                return a.id < b.id;
            });
        }
        else if(q.category == "name"){
            sort(temp.begin(), temp.end(), [change](const entry &a, const entry &b){
                if(a.lname != b.lname) {
                    if (change == "desc") return a.lname > b.lname;
                    return a.lname < b.lname;
                }
                if(a.fname != b.fname){
                    if (change == "desc") return a.fname > b.fname ;
                    return a.fname < b.fname ;
                }
                if (change == "desc") return a.id > b.id;
                return a.id < b.id;
            });
        }

        

        cout << "Query: " << q.category << " " << q.af << " " << q.times << '\n';
        for (int i = 0; i < q.times; ++i) print_struct(temp[i]);

    }
    return 0;
}