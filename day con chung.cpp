#include <bits/stdc++.h>
using namespace std;

const int MAX = 10005;
int n, m;
int x[MAX], y[MAX];
int mem[MAX][MAX];

int LCS(int i, int j)
{
    if(i == 0 || j == 0) return 0;
    if(mem[i][j] != -1) return mem[i][j];

    int res = 0;
    res = max(res, LCS(i-1, j));
    res = max(res, LCS(i, j-1));
    if(x[i] == y[j]) res =  max(res,1+LCS(i-1, j-1));

    mem[i][j] = res;
    return res;
}
void Trace(int i, int j) {
    if (i == 0 || j == 0) return;
    if (x[i] == y[j] && mem[i][j] == 1 + mem[i-1][j-1]) {
        Trace(i- 1, j - 1);
        cout << x[i];
        return;
    }
    if (mem[i][j] == mem[i-1][j]) {
        Trace(i- 1, j);

        return;
    }
    if (mem[i][j] == mem[i][j-1]) {
        Trace(i, j - 1);

        return;
    }
 }

int main()
{
    memset(mem, -1, sizeof(mem));
    cin >>n>>m;
    for(int i=1; i<=n; i++) {
        cin>>x[i] ;
    }
    for(int i=1; i<=m; i++) {
        cin>>y[i];
    }
    cout << LCS(n, m) << "\n";
    for(int i=0; i<=n; i++){
        for(int j=0; j<=m; j++){
            cout<< mem[i][j]<<" ";
        }
        cout<<endl;
    }
    Trace(n,m);
    return 0;
}
