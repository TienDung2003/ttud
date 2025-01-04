//Cho một mạng G = (V, E) là một đồ thị có trọng số có hướng. Các nút s là nguồn và nút t là đích. c(u,v) là dung lượng của cung (u,v). Tìm luồng cực đại trên G.
#include<bits/stdc++.h>

using namespace std;


int n, m, s, t;
int capacity[101][101];
int parent[101];

void nhap(){
	cin >> n >> m;

    cin >> s >> t;
    int u, v, c;
    for (int i = 0; i < m; i++) {

        cin >> u >> v >> c;
        capacity[u][v] = c;
    }

}
bool bfs(int s, int t) {
    vector<bool> visited(n, false);
    queue<int> q;
    q.push(s);
    visited[s] = true;
    parent[s] = -1;

    while (!q.empty()) {
        int u = q.front();
        q.pop();

        for (int v = 1; v <=n; v++) {
            if (!visited[v] && capacity[u][v] > 0) {
                q.push(v);
                parent[v] = u;
                visited[v] = true;
            }
        }
    }

    return visited[t];
}

//  Edmonds-Karp
void edmondsKarp(int s, int t) {
    int maxFlow = 0;

    while (bfs(s, t)) {
        int pathFlow = 10000000;
        int v = t;

        while (v != s) {
            int u = parent[v];
            pathFlow = min(pathFlow, capacity[u][v]);
            v = u;
        }

        v = t;
        while (v != s) {
            int u = parent[v];
            capacity[u][v] -= pathFlow;
            capacity[v][u] += pathFlow;
            v= u;
        }

        maxFlow += pathFlow;
    }
	cout<<maxFlow;

}

int main() {
	memset(capacity, 0, sizeof(capacity));
    nhap();
    edmondsKarp(s, t);

    return 0;
}
