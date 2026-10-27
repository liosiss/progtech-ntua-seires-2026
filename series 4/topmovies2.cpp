#include <iostream>
#include <string>
#include <set>
#include <unordered_map>
using namespace std;

struct my_comparator {
    bool operator()(const pair<string, int>& a, const pair<string, int>& b) const {
        if (a.second != b.second) {
            return a.second > b.second; 
        }
        return a.first < b.first; 
    }
};

struct reviews {
    int sum;
    int total_reviews;

};

int main() {
    int k;
    cin >> k;
    string nm, vw; //movie name, viewer name
    int rt; // rating
    unordered_map<string, reviews> mpp;
    int cnt = 0;
    while (cin >> nm >> vw >> rt) {
        if (rt > 100 || rt < 0) continue;
        mpp[nm].total_reviews++;
        mpp[nm].sum += rt;
    }

    set<pair<string, int>, my_comparator> st;

    for (const auto &it : mpp) {
        st.insert({it.first, it.second.sum / it.second.total_reviews});
    }

    for (const auto &it : st) {
        cnt++;
        if (cnt > k) break;
        cout << it.first << " " << it.second << '\n';
    }

    return 0;
}
