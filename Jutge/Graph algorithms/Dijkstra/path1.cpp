#include <iostream>
#include <queue>
#include <vector>
using namespace std;

struct edge {
    int v;
    int cost;

    edge(): v(0), cost(0) {}
    edge(int w, int c): v(w), cost(c) {}
    friend bool operator< (const edge& a, const edge& b) {return a.cost > b.cost;}
};

int dijkstra(vector<vector<edge>>& graph, int x, int y) {
    priority_queue<edge> cua;
    vector<bool> visited(graph.size(),false);
    vector<int> costs(graph.size(),-1);
    cua.push(edge(x,0));

    while (not cua.empty()) {
        edge e = cua.top();
        cua.pop();
        if (not visited[e.v]) {
            visited[e.v] = true;
            if (e.v == y) return e.cost;
            for (int i = 0; i < graph[e.v].size(); ++i) {
                edge ne (graph[e.v][i].v,graph[e.v][i].cost);
                if (costs[ne.v] == -1 or costs[ne.v] > ne.cost + e.cost) {
                    costs[ne.v] = ne.cost + e.cost;
                    cua.push(edge(graph[e.v][i].v,graph[e.v][i].cost + e.cost));
                }
            }
        }
    }
    return -1;
}

int main() {
    int n, m;
    while (cin >> n >> m) {
        vector<vector<edge>> graph(n);
        for (int i = 0; i < m; ++i) {
            int j;
            edge e;
            cin >> j >> e.v >> e.cost;
            graph[j].push_back(e);
        }

        int x, y;
        cin >> x >> y;
        int d = dijkstra(graph,x,y);
        if (d == -1) cout << "no path from " << x << " to " << y << endl;
        else cout << d << endl;
    }
}