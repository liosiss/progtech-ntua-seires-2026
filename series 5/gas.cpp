#include <iostream>
#include <set>
#include <vector>
#include <map>
using namespace std;



class roads {
    private:

    vector<vector<pair<int, int>>> graph;  // 1) vertice 2) distance

    public:

    bool AddRoad (int a, int b, int c) {
        graph[a].emplace_back(b, c);
        graph[b].emplace_back(a, c);
        return;
    }

    




};