#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;



class Graph {
    private:
    int vertices;
    vector<vector<int>> graph;

    public:
    Graph(int v) {
        vertices = v;
        graph.resize(v);
    }

    ~Graph() { graph.clear(); }

    void addEdge(int u, int v) {
        if (u == v) return;
        auto& temp = graph[u];
        if (find(temp.begin(), temp.end(), v) == temp.end()) {
        temp.push_back(v);
        }
    } 



    bool cycle(vector<int> &path) const{
        vector<bool> vis(vertices, false);
        vector<bool> stk(vertices, false);
        for (int i = 0; i < vertices; ++i) {
            if (!vis[i]) {
                if (help_cycle(i, path, vis, stk)) return true;
            }
        }
        return false;
    }

    bool help_cycle(int x, vector<int> &path, vector<bool> &vis, vector<bool> &stk) const{
        vis[x] = true;
        path.push_back(x);
        stk[x] = true;
        for (const auto &it : graph[x]) {
            if (!vis[it]){
                if (help_cycle(it, path, vis, stk)) return true;
            }
            else if (stk[it]) {
                path.push_back(it);
                return true;
            }
        }

        stk[x] = false;
        path.pop_back();
        return false;
    }


};



int main() {
 int V, E;
 cin >> V >> E;
 Graph g(V);
 for (int i = 0; i < E; ++i) { int u, v; cin >> u >> v; g.addEdge(u, v); }
 vector<int> path;
 bool c = g.cycle(path);
 if (c) {
     cout << 'CYCLE: ';
for (int i = 0; i < path.size(); ++i)
 cout << path[i] << (i == path.size()-1 ? '\n' : ' ' );
} else {
 cout << 'NO CYCLE' << endl;
 }
 
}