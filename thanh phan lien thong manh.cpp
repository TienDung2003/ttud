//Cho đồ thị có hướng G=(V,E) trong đó V={1,. . ., N} là số nút và tập E có M cung. Tính số thành phần liên thông mạnh của G
#include <bits/stdc++.h>
using namespace std;

const int MAX = 1e5 + 5;
int n, m;
int cnt = 0;
vector<int> adj[MAX], t_adj[MAX];
stack<int> st;
bool used[MAX];

void input(){
    cin>>n>>m;
    int x,y;
    for(int i=0; i<m; i++){
        cin>>x>>y;
        adj[x].push_back(y);
        t_adj[y].push_back(x);
    }

}

void dfs1(int u){
    used[u]=true;
    for (int v : adj[u]){
        if (!used[v]){
            dfs1(v);
        }
    }
    st.push(u);
    //cout<<u<<" ";
}

void dfs2(int u){
    used[u]=true;
    //hien thi cac thanh phan lien thong
    //cout<<u<<" ";
    for (int v : t_adj[u]){
        if (!used[v]){
            dfs2(v);
        }
    }
}

void solve(){
    memset(used, false, sizeof(used));
    for(int i=1; i<= n; i++){
        if(!used[i]) {

            dfs1(i);

        }
    }
    cout<<endl;
    memset(used, false, sizeof(used));
    while(!st.empty()){
        int u =st.top();
        st.pop();
        if(!used[u]) {
            dfs2(u);
            //cout<<endl;
            cnt++;
        }
    }
}
int main()
{
   input();
   solve();
    cout<<cnt;
    return 0;
}
