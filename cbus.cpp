//Có n hành khách 1, 2, …, n. Hành khách i muốn đi từ điểm i đến điểm i + n (i = 1,2,…, n).
//Có một xe buýt nằm tại điểm 0 và có k chỗ để chở hành khách (tức là tại bất kỳ thời điểm nào, có nhiều nhất k hành khách trên xe buýt).
//Bạn được cung cấp ma trận khoảng cách c trong đó c(i,j) là khoảng cách di chuyển từ điểm i đến điểm j (i, j = 0,1,…, 2n).
//Tính tuyến đường ngắn nhất cho xe buýt, phục vụ n hành khách và quay trở lại điểm 0.
#include <bits/stdc++.h>
using namespace std;

const int MAX = 25;
int n, k, c[MAX][MAX], c_min = INT_MAX;
int load=0, road[MAX], road_best[MAX], f=0, f_min = INT_MAX;
bool visited[MAX];

bool check(int i, int v)
{
    if(visited[i]) return false;
    // neu chua duoc tham
    if(i <= n) {
        if(load + 1 > k) return false;
    }
    else {
        if(!visited[i-n]) return false;
    }
    return true;
}

void GhiNhan()
{
    int d = f + c[road[2*n]][0];
    if(d<f_min){
        f_min = d;
        for(int i=1; i<=2*n+1;i++)
        road_best[i]=road[i];
    }

}

void Try(int v)
{
    for(int i=1; i<=2*n; i++) {
        if(check(i,v)) {
            road[v] = i;
            if(i <= n) load++;
            else load--;
            f += c[road[v-1]][i];
            visited[i] = true;
            if(v == 2*n) GhiNhan();
            else if(f + (2*n+1-v)*c_min < f_min) Try(v+1);
            if(i <= n) load--;
            else load++;
            f -= c[road[v-1]][i];
            visited[i] = false;
        }
    }
}

int main()
{
    cin>>n>>k;
    for(int i=0; i<=2*n; i++) {
        for(int j=0; j<=2*n; j++) {
            cin>>c[i][j];
            if(i != j) c_min = min(c_min, c[i][j]);
        }
    }
    road[0] = 0;
    Try(1);
    cout << f_min << "\n";
    for(int i=1; i<=2*n+1;i++)
        cout<< road_best[i];
    return 0;
}
