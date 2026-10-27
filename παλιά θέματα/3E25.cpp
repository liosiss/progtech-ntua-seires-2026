#include <iostream>
#include <vector>
#include <set>
using namespace std;

enum color{blank, white, black};

set<int> same_color(int u) {
    vector<color> vec(N, blank);
    vec[u] = white;
    set<int> same;
    same.insert(u);
    bool w = help(u, same);
    return same;
}

bool help(int u, set<int> &st) {
    for( const auto &it : edges[u]) {
        if (!visited[it]) vec[it]=white;
        else {
            if(vec[it] == vec[u]) return false;
            else st.insert[it];
            help(it, st);
        }
    }
    return true;
}