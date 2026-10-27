#include <iostream>
#include <vector>
#include <set>

using namespace std;

int up (vector<int> parent, int vec){
    if (parent[vec] == vec ) return vec ;
    else parent[vec] = up(parent, parent[vec]);
}


int main() {
    int n, m, k;
    cin >> n >> m >> k;
    vector<int> parent(n);
    for(int i = 0; i < n; ++i) {
        parent[i + 1] = i + 1;
    }

    for (int i = 0; i < m; ++i) {
        int a, b;
        cin >> a >> b;
        if (parent[b] > parent[a]){
            parent[b] = parent[a];
        }
        else if (parent[a] > parent[b]) {
            parent[a] = parent[b];
        }
    }

    set<int> dif;
    int x;
    for (const auto &it : parent) {
        x = up(parent, it);
        dif.insert(x);
    }

    cout << endl;
    int teams = dif.size() - k;
    cout << (teams > 1 ? teams : 1) << endl;
    return 0;

}