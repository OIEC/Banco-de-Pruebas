#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, M, T;
    cin >> N >> M >> T;

    vector<vector<int>> adj(N + 1);

    for (int i = 0; i < M; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    vector<int> dist(N + 1, -1);
    queue<int> q;

    dist[N] = 0;
    q.push(N);

    while (!q.empty()) {
        int u = q.front();
        q.pop();

        for (int v : adj[u]) {
            if (dist[v] == -1) {
                dist[v] = dist[u] + 1;
                q.push(v);
            }
        }
    }

    int respuesta = 0;

    for (int i = 1; i < N; i++) {
        if (dist[i] != -1 && dist[i] < T) {
            respuesta++;
        }
    }

    cout << respuesta << endl;

    return 0;
}
