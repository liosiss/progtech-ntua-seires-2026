#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Graph {
private:
    int vertices;
    vector<vector<int>> graph;

    bool help_cycle(int node,
                    vector<int>& path,
                    vector<bool>& visited,
                    vector<bool>& recStack) const
    {
        visited[node] = true;
        recStack[node] = true;

        path.push_back(node);

        for (int neighbor : graph[node]) {

            if (!visited[neighbor]) {

                if (help_cycle(neighbor, path, visited, recStack))
                    return true;
            }

            else if (recStack[neighbor]) {

                auto start = find(path.begin(), path.end(), neighbor);

                vector<int> cyclePart(start, path.end());

                path = cyclePart;

                return true;
            }
        }

        recStack[node] = false;
        path.pop_back();

        return false;
    }

public:
    Graph(int v) : vertices(v) {
        graph.resize(v);
    }

    void addEdge(int u, int v) {

        if (u == v) return;

        auto& temp = graph[u];

        if (find(temp.begin(), temp.end(), v) == temp.end()) {
            temp.push_back(v);
        }
    }

    bool cycle(vector<int>& path) const {

        vector<bool> visited(vertices, false);
        vector<bool> recStack(vertices, false);

        path.clear();

        for (int i = 0; i < vertices; ++i) {

            if (!visited[i]) {

                if (help_cycle(i, path, visited, recStack))
                    return true;
            }
        }

        return false;
    }
};

int main() {

    int V, E;
    cin >> V >> E;

    Graph g(V);

    for (int i = 0; i < E; ++i) {
        int u, v;
        cin >> u >> v;
        g.addEdge(u, v);
    }

    vector<int> path;

    bool c = g.cycle(path);

    if (c) {

        cout << "CYCLE: ";

        for (int i = 0; i < path.size(); ++i)
            cout << path[i]
                 << (i == path.size() - 1 ? '\n' : ' ');
    }
    else {

        cout << "NO CYCLE" << endl;
    }
}
