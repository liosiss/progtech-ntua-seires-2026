#include <iostream>
#include <set>
#include <map>
#include <string>
#include <fstream>
using namespace std;

int main() {
    ifstream F;
    F.open("words.txt");
    if (!F.is_open()) {
        cerr << "the file did not open";
        return 1;
    }
    
    set<string> st1;
    string a;
    while(F >> a) st1.insert(a);

    F.close();

    set<string> unknown;
    map<string, int> freq;
    while(cin >> a) {
        if(st1.find(a) == st1.end()) unknown.insert(a);
        else {
            freq[a]++;
        }
    }

    for (const auto &it : freq) {
        cout << it.first << " " << it.second << endl;
    }
    cout << unknown.size() << endl;

    return 0;

}