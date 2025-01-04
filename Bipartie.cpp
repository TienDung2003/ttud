/*Có n nhiệm vụ 1, . . .,n và m nhân viên 1, . . , m. T(i) là tập hợp các nhân viên có thể thực hiện nhiệm vụ i (i=1, . . ., n).
Tính toán sự phân công nhân viên cho các nhiệm vụ sao cho mỗi nhiệm vụ được phân công cho nhiều nhất một nhân viên
và mỗi nhân viên không thể được phân công cho nhiều hơn một nhiệm vụ và số lượng nhiệm vụ được phân công là tối đa.
Đầu vào
Dòng 1: chứa 2 số nguyên dương n và m (1 <= n,m <= 10000)
Dòng i+1 (i=1, . . .,n) chứa số nguyên dương k và k số nguyên của T(i)
Đầu ra
Viết số lượng nhiệm vụ tối đa được giao cho nhân viên.*/
#include <bits/stdc++.h>
using namespace std;

const int MAXN = 10005; // Giới hạn số lượng nhiệm vụ và nhân viên
vector<int> adj[MAXN];  // Danh sách kề
int match[MAXN];        // match[v]: nhân viên v được gán cho nhiệm vụ nào
bool visited[MAXN];     // visited[v]: kiểm tra nhân viên v trong DFS

// DFS tìm đường tăng luồng
bool dfs(int task) {
    for (int employee : adj[task]) {
        if (visited[employee]) continue;
        visited[employee] = true;
        // Nếu nhân viên chưa được gán hoặc có đường tăng luồng
        if (match[employee] == -1 || dfs(match[employee])) {
            match[employee] = task; // Gán nhân viên cho nhiệm vụ
            return true;
        }
    }
    return false;
}

int main() {
    int n, m;
    cin >> n >> m;

    // Nhập danh sách kề
    for (int i = 1; i <= n; ++i) {
        int k; cin >> k;
        for (int j = 0; j < k; ++j) {
            int employee; cin >> employee;
            adj[i].push_back(employee);
        }
    }

    // Khởi tạo mảng match
    memset(match, -1, sizeof(match));

    int maxTasks = 0;

    // Tìm matching tối đa
    for (int i = 1; i <= n; ++i) {
        memset(visited, false, sizeof(visited));
        if (dfs(i)) {
            ++maxTasks;
        }
    }

    cout << maxTasks << endl;
    return 0;
}
