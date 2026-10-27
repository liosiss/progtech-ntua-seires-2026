#include <iostream>
#include <map>
#include <set>
using namespace std;

int main() {
    map<int, set<string>> mpp;
    string a;
    while(cin >> a) {
        mpp[a.length()].insert(a);
    }
    for(const auto &it : mpp) {
        cout << "Length " << it.first << ":";
        for(const auto &it2 : it.second) {
            cout << " " << it2;
        }
        cout << endl;
    }
    return 0;
} 