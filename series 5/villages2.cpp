#include <iostream>
#include <vector>
#include <set>
using namespace std;


class DisjoinSet {
    private:
    vector<int> rank, parent;

    public:

    DisjoinSet(int n) {
        rank.resize(n+1, 0);
        parent.resize(n+1);
        for (int i = 1; i <= n; ++i){
            parent[i] = i;
        }
    }

    

    int findUparent (int v) {
        if (parent[v] == v) return v;
        else {
            parent[v] = findUparent(parent[v]);
        }
    }

    void unionbyrank (int v1, int v2) {
        int upv1 = findUparent(v1);
        int upv2 = findUparent(v2);
        if (upv1 == upv2) return;
        int dif = rank[upv1] - rank[upv2];
        if (dif < 0) {
            parent[upv1] = upv2;
            rank[upv1] -= dif;
        }
        else if (dif > 0) {
            parent[upv2] = upv1;
            rank[upv2] += dif;
        }
        else {
            parent[upv2] = upv1;
            rank[upv1]++;
        }
    }
};


int main() {
    int n, m, k;
    cin >> n >> m >> k;
    DisjoinSet ds(n);
    for (int i = 0; i < m; ++i) {
        int a, b;
        cin >> a >> b;
        ds.unionbyrank(a, b);
    }

    set<int> dif;
    for (int i = 1; i <= n; ++i) {
        dif.insert(ds.findUparent(i));
    }

    int teams = dif.size() - k;
    cout << (teams > 1 ? teams : 1) << endl;
    return 0;
}

//cout << "parent of: " << i << " is: " << ds.getparent(i) << endl;