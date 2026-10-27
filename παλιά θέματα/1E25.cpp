#include <iostream>
#include <string>
#include <map>
#include <fstream>
using namespace std;

int main() {
    ifstream file("phonebook.txt");
    if(!file.is_open()) {
        cerr << "the file didn't open properly!";
        return 1;
    }

    map<string, string> phonebook;
    string number, name;
    while(file >> number >> name) phonebook[number] = name;

    file.close();

    map<string, int> total_phonecalls;
    map<string, map<string, int>> call_to;
    string a, b;
    while(cin >> a >> b) {
        string caller, called;
        if(phonebook.find(a) == phonebook.end()) caller = "unknown";
        else caller = phonebook[a];

        if(phonebook.find(b) == phonebook.end()) called = "unknown";
        else called = phonebook[b];

        total_phonecalls[caller]++;
        call_to[caller][called]++;
    }

    for (const auto &it : call_to) {
        cout << it.first << " " << total_phonecalls[it.first];
        for (const auto &it2 : it.second) {
            cout << " " << it2.first << " " << it2.second;
        }
        cout << endl;
    }

    return 0;
}