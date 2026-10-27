#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main () {
    int cnt;
    cin >> cnt;
    string word;
    char c;
    vector<string> yn;
    for (int i = 0; i < cnt; ++i) {
        cin >> word >> c;
        if (word.find(c) != string::npos) yn.push_back("yes");
        else yn.push_back("no");
    }
    for(auto it : yn) {
        cout << it << endl;
    }
    return 0;
}