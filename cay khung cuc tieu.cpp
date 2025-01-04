#include<iostream>
#include<utility>
#include<vector>
#include<cstring>
#include<queue>
using namespace std;

int n,m;
vector<pair<int,int>> adj[40001];
bool used[40001];

void nhap(){
	cin>>n >>m;
	int x,y,w;
	for(int i=0; i<m; i++){
		cin>> x>> y>> w;
		adj[x].push_back({y,w});
		adj[y].push_back({x,w});
	}
	memset(used, false, sizeof(used));
}

void prim(int u){
	priority_queue< pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> q;
	int d =0; //trong so
	q.push({0, u});
	while( !q.empty()){
		pair<int, int> top =q.top();
		q.pop();
		int dinh= top.second;
		int w= top.first;
		if(used[dinh]) continue;
		d+= w;
		used[dinh]= true;
		for( auto c: adj[dinh]){
			int y= c.first;
			int wy= c.second;
			if(!used[y]){
				q.push({wy, y});
			}
		}
	}
	cout<<d;

}

int main(){
	nhap();
	prim(1);
	return 0;
}
