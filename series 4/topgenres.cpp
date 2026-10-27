#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <set>
using namespace std;

struct MyComparator {
    bool operator()(const pair<string, int>& a, const pair<string, int>& b) const {
        if (a.second != b.second) {
            return a.second > b.second; 
        }
        return a.first < b.first; 
    }
};

int main () {
    int n, g;
    cin >> n >> g;
    string movie, genre;
    multimap<string, string> mpp;
    for (int i = 0; i < n; i++){
        cin >> movie >> genre;
        mpp.insert({movie, genre});        
    }

    string a, b;
    int c;
    map<string, int> mpp2;
    while (cin >> a >> b >> c) {
        if (c < 0 || c >= 100) continue;
        auto it = mpp.find(a); 
            if (it != mpp.end()) { 
                mpp2[it->second]++;
            }
    }


    set<pair<string, int>, MyComparator> s;
    for (const auto &it : mpp2) {
        s.insert({it.first, it.second});
    }

    int cnt = 0;
    for (auto it =s.begin(); it != s.end(); it++){
        cnt++;
        if (cnt > g) break;
        cout << it->first << " " << it->second << endl;
    }

    return 0;
}

