#include <bits/stdc++.h>
using namespace std;
const int INF = 1e9; const int N = 1001;
const int XMAX = 1001;
int D[N], mem[N][XMAX];

 int MinCoin(int i, int x){
    if (x < 0 || i == 0) return INF;
    if (x == 0) {
        mem[i][x] =0;
            return 0;}
    if (mem[i][x] != -1) return mem[i][x];
    int res = INF;
    res = min(res, 1 + MinCoin(i, x - D[i]));
    res = min(res, MinCoin(i- 1, x));
    mem[i][x] =res;
    return  res;
 }

 void Trace(int i, int x) {
    if (x <= 0 || i == 0) return;

    if (mem[i][x] == 1 + mem[i][x - D[i]]){

        cout << D[i] << ' ';
        Trace(i, x - D[i]);
 } else Trace(i- 1, x);
 }

 int main(){
    memset(mem, -1, sizeof(mem));
    int n, x;
    cin>>n>>x;
    for(int i=1; i<=n; i++){
        cin>>D[i];
    }
    int a=MinCoin(n,x);
    cout<<a;
    //Trace(n,x);

 }
