#include <iostream>
#include <vector>
 
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    vector<int> node(n, 0);
    vector<int> path;

    int a, b;
    for (int  i = 0; i < m; ++i){
        cin >> a >> b;
        node[a]++;
        node[b]++;
    }

    for (int i = 0; i < n; ++i) {
        if (node[i] % 2 != 0) {
            path.push_back(i);
        }
    }

    int sz = path.size();

    if (sz == 0) {
        cout << "CYCLE\n"; 
    }
    else if (sz == 2)
    {
        if (path[0] < path[1]){
            cout << "PATH " << path[0] << " " << path[1] << '\n';
        }
        else {
            cout << "PATH " << path[1] << " " << path[0] << '\n';
        }
    }
    else {
        cout << "IMPOSSIPLE\n";
    }

    return 0;


}