//Cho một vật liệu có hình chữ nhật với chiều cao H và chiều rộng W.
//Chúng ta cần cắt vật liệu này thành n vật liệu con hình chữ nhật nhỏ hơn có kích thước (h1,w1), (h2, w2), ..., (hn, wn).
//Viết chương trình để kiểm tra xem chúng ta có thể thực hiện phép cắt này hay không.
#include <bits/stdc++.h>
using namespace std;

const int MAX = 11;
int H, W, n, wk, hk, w[MAX], h[MAX];

vector<pair<int,int> > v;
int mark[MAX][MAX];
struct index1 {
    int x,y,z;
};
index1 m[20];
bool check(int vo, int vx, int vy, int k)
{
    int hk = h[k];
    int wk = w[k];
    if(vo == 1) {
        wk = h[k];
        hk = w[k];
    }
    if(vx + wk > W) return false;
    if(vy + hk > H) return false;
    for(int i=vx; i<=vx+wk-1; i++)
        for(int j=vy; j<=vy+hk-1; j++) {
            if(mark[i][j]) return false;
        }
}

void doMark(int vo, int vx, int vy, int k, bool mark_value)
{
    int hk = h[k];
    int wk = w[k];
    if(vo == 1) {
        wk = h[k];
        hk = w[k];
    }

    for(int i=vx; i<=vx+wk-1; i++)
        for(int j=vy; j<=vy+hk-1; j++) {
            mark[i][j] = mark_value;
        }
    m[k].x= vx;
    m[k].y= vy;
    m[k].z= vo;
}

void GhiNhan()
{
    cout << "1" << "\n";
    //for(int i=0; i<n; i++){
    //    cout<<m[i].x<<m[i].y<<m[i].z;
    //}
    exit(1);
}

void Try(int k)
{
    for(int vo=0; vo <= 1; vo++) {
        int hk = h[k];
        int wk = w[k];
        if(vo == 1) {
            wk = h[k];
            hk = w[k];
        }
        for(int vx=0; vx <= W-wk; vx++)
            for(int vy=0; vy <= H-hk; vy++) {
                if(check(vo, vx, vy, k)) {
                    doMark(vo, vx, vy, k, 1);
                    if(k==(n-1)) GhiNhan();
                    else Try(k+1);
                    doMark(vo, vx, vy, k, 0);
                }
            }
    }
}

int main()
{
    cin>>H>>W>>n;

    int p, q;
    for(int i=0; i<n; i++) {
        cin>>p>>q;
        h[i]=p;
        w[i]=q;
    }

    Try(0);
    cout << "0" << "\n";

    return 0;
}
