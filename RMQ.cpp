//Given a sequence of n integers a0,.n-1. We denote rmq(i,j) the minimum element of the sequence ai, ai+1, . . .,aj
//. Given m pairs (i1, j1),. . .,(im, jm), compute the sum Q = rmq(i1,j1) + . . . + rmq(im, jm)
#include<bits/stdc++.h>

using namespace std;

int n,t;
int M[32][1000001];
int a[1000001];
void preproccessing(){
    for(int j=0; j<n; j++) M[0][j] = j;
    for(int i=1; (1<<i) <=n; i++){
        for(int j=0; j+(1<<i)  <= n; j++){
            if(a[M[i-1][j]] < a[M[i-1][j+ (1<<(i-1))]]) M[i][j]= M[i-1][j];
            else M[i][j]= M[i-1][j+ (1<<(i-1))];
        }
    }
}

int rmq(int i, int j){
    int k = (int)log2(j-i+1);
    if(a[M[k][i]] <= a[M[k][j-(1<<k)+1]]) {
        return a[M[k][i]];
    }
    else return a[M[k][j-(1<<k)+1]];
}

int main(){
    int sum=0;
    cin>>n;
    for (int i=0; i<n; i++) cin>> a[i];
    preproccessing();
    cin>>t;
    int i,j;
    while(t--){
        cin>>i>>j;
        sum+= rmq(i,j);
    }
    cout<<sum;
    return 0;
}
