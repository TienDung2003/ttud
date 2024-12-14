//Một mê cung hình chữ nhật được biểu diễn bởi 0-1 ma trận NxM trong đó A[i,j] = 1
//thể hiện ô (i,j) là tường gạch và A[i,j] = 0 thể hiện ô (i,j) là ô trống,
 //có thể di chuyển vào. Từ 1 ô trống, ta có thể di chuyển sang
// 1 trong 4 ô lân cận (lên trên, xuống dưới, sang trái, sang phải) nếu ô đó là ô trống.
// Xuất phát từ 1 ô trống trong mê cung, hãy tìm đường ngắn nhất thoát ra khỏi mê cung.
#include<bits/stdc++.h>
using namespace std;
int n, m, i, j;
int a[1000][1000], d[1000][1000];
int dx[4]= {1, 0, -1, 0},dy[4]= {0, 1, 0, -1};

int bfs(int i, int j){
    queue<pair<int, int>> q;
    q.push({i,j});
    d[i][j]= 0;
    a[i][j]= 1;
    while(!q.empty()){
            pair<int, int> top = q.front(); q.pop();
        for(int k=0; k<4; k++){
            int i1= top.first + dx[k];
            int j1= top.second + dy[k];
            if (i1 <1 || i1 >n || j1 <1 || j1>m){
                return d[top.first][top.second] +1;
            }
            if(a[i1][j1] !=1 ){
                d[i1][j1] = d[top.first][top.second] +1;
                q.push({i1,j1});
                a[i1][j1] = 1;
            }
        }
    }
    return -1;
}

void inp(){
    ios_base::sync_with_stdio(false);cin.tie(0);
    cin>> n>>m>>i>>j;
    for (int c=1; c<=n ;c++){
        for (int b=1; b<=m ;b++) cin>> a[c][b];
    }
}
int main(){
    inp();
    int result = bfs(i,j);
    cout<< result;
    return 0;
}
