#include <iostream>
#include <string>
#include <unordered_map> 
#include <set>
using namespace std;

struct my_comparator {
    bool operator()(const pair<string, int>& a, const pair<string, int>& b) const {
        if (a.second != b.second) {
            return a.second > b.second; 
        }
        return a.first < b.first; 
    }
};

int main() {
    int n, g;
    cin >> n >> g;
    unordered_map<string, string> mpp;
    string a, b;
    for (int i = 0; i < n; ++i) {
        cin >> a >> b;
        if (mpp.find(a) != mpp.end()) continue;
        mpp.emplace(a, b);
    }

    int rt;
    unordered_map<string, int> mpp2;
    while (cin >> a >> b >> rt) {
        if (rt > 100 || rt < 0 || mpp.find(a) == mpp.end()) continue;
        mpp2[mpp[a]] ++;
    }

    set<pair<string, int> , my_comparator> st;
    for (const auto &it : mpp2) {
        st.insert({it.first, it.second});
    }

    int cnt = 0;
    for (const auto &it : st) {
        cnt++;
        if (cnt > g) break;
        cout << it.first << " " << it.second << '\n';
    }

    return 0;
}