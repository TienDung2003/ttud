/*Có n thành phố 1, 2, ..., n. Giữa 2 thành phố i và j có thể có 1 con đường (2 chiều) kết nối giữa chúng.
Mỗi thành phố i có tuyến buýt i với C[i] là giá vé mỗi khi lên xe và D[i] là số thành phố tối đa mà buýt i có thể đi đến trên 1 hành trình đi qua các con đường kết nối.
Hãy tìm cách đi từ thành phố 1 đến thành phố n với số tiền phải trả là ít nhất
Input
Dòng 1: chứa 2 số nguyên dương n và m trong đó n là số thành phố và m là số con đường kết nối các thành phố (1 <= n <= 5000, 1 <= m <= 10000)
Dòng i+1 (i = 1,2,...,n): chứa 2 số nguyên dương C[i] và D[i] (1 <= C[i] <= 10000, 1 <= D[i] <= 100)
Dòng n+1+i (i = 1, 2, ..., m): chứa 2 số nguyên dương i và j trong đó giữa thành phố i và j có con đường kết nối*/
#include <bits/stdc++.h>
#define pii pair<int,int>
using namespace std;

const int MAX = 5005;
const int _INT_MAX = 1e9;
int n, m;
int C[MAX], D[MAX];
vector<int> adj[MAX];
int weight[MAX][MAX]; //chi phi di tu tanh pho i den j
int d[MAX]; //khong cach tu thanh phanh j den root => qua toi da chua
bool visited[MAX];

void BFS(int i)
{
    for(int j=1; j<=n; j++) d[j] = -1;
    queue<int> q;
    q.push(i);
    d[i] = 0;
    while(!q.empty()) {
        int u = q.front(); q.pop();
        weight[i][u] = C[i];
        for(auto v : adj[u]) {
            if(d[v] >= 0) continue;
            d[v] = d[u] + 1;
            if(d[v] <= D[i]) q.push(v);
        }
    }
}

void buildGraph()
{
    for(int i=1; i<=n; i++)
        for(int j=1; j<=n; j++) {
            weight[i][j] = _INT_MAX;
        }
    for(int i=1; i<=n; i++) {
        BFS(i);
    }
}

int dijkstra(int s, int t)
{
    for(int i=1; i<=n; i++) {
        d[i] = weight[s][i];
        visited[i] = false;
    }
    d[s] = 0; visited[s] = true;
    for(int i=1; i<=n; i++) {
        int u = -1;
        int _min = INT_MAX;
        for(int j=1; j<=n; j++) {
            if(!visited[j]) {
                if(d[j] < _min) {
                    _min = d[j];
                    u = j;
                }
            }
        }
        visited[u] = true;
        if(u == t) break;
        for(auto x : adj[u]) {
            if(!visited[x]) {
                if(d[x] > d[u] + weight[u][x]) {
                    d[x] = d[u] + weight[u][x];
                }
            }
        }
    }
    return d[t];
}

int main()
{
    scanf("%d%d", &n, &m);
    for(int i=1; i<=n; i++) {
        scanf("%d%d",  &C[i], &D[i]);
    }
    for(int i=1; i<=m; i++) {
        int a, b;
        scanf("%d%d", &a, &b);
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    buildGraph();
    cout << dijkstra(1,n) << "\n";

    return 0;
}
