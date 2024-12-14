//Vào đầu học kỳ, trưởng khoa khoa học máy tính D phải phân công các khóa học cho giáo viên một cách cân bằng.
//Mỗi giáo viên t∈T có một danh sách ưu tiên là danh sách các khóa học mà anh/cô ấy có thể dạy tùy thuộc vào chuyên môn của mình.
//Chúng ta đã biết một danh sách các cặp khóa học xung đột không thể được phân công cho cùng một giáo viên vì
//các khóa học này đã được lên lịch trong cùng một khoảng thời gian của thời khóa biểu.
//Tải trọng của một giáo viên là số lượng các khóa học được phân công cho người đó.
//Làm thế nào để phân công nn khóa học cho mm giáo viên sao cho mỗi khóa học được phân công cho một giáo viên đều nằm trong danh sách ưu tiên của giáo viên đó,
//không có hai khóa học xung đột nào được phân công cho cùng một giáo viên và tải trọng tối đa là tối thiểu.
//Đầu vào
//Đầu vào bao gồm các dòng sau
//Dòng 1: chứa hai số nguyên m và n (1≤m≤10, 1≤n≤30)
//Dòng i+1: chứa số nguyên dương k và k số nguyên dương biểu thị các khóa học mà giáo viên i có thể dạy (∀i=1,…,m)
//Dòng m+2: chứa số nguyên k
//Dòng i+m+2: chứa hai số nguyên i và j biểu thị hai hướng xung đột (∀i=1,…,k)
//Đầu ra
//Đầu ra chứa một số duy nhất là số lượng giáo viên tối đa trong giải pháp tìm được và giá trị -1 nếu không tìm thấy giải pháp.
#include <bits/stdc++.h>
using namespace std;

const int MAX = 50;
int m, n, k;
int v[MAX][MAX];
int conflict[MAX][MAX];
map<int, vector<int>> object; //{giao vien, danh sach mon hoc}
vector<int> size_object;
int res = INT_MAX, max_object = INT_MIN;

bool check(int i, int t)
{
    if(v[i][t] != 1) return false;
    for(auto x : object[i])
        if(conflict[x][t]==1) return false;
    return true;
}

void GhiNhan()
{
    int max_e = *max_element(size_object.begin(), size_object.end());
    res = min(res, max_e);
}

void Try(int t)
{
    for(int i=0; i<m; i++) {
        if(check(i, t)) {
            object[i].push_back(t);
            size_object[i]++;
            int temp = max_object;
            max_object = max(max_object, size_object[i]);
            if(t==n) GhiNhan();
            else if(max_object < res) Try(t+1);
            object[i].pop_back();
            size_object[i]--;
            max_object = temp;
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    scanf("%d%d", &m, &n);
//    build();
    int a;
    for(int i=0; i<m; i++) {
        scanf("%d", &k);
        for(int j=0; j<k; j++) {
            scanf("%d", &a);
            v[i][a] = 1;
        }
        size_object.push_back(0);
    }
    scanf("%d", &k);
    int p, q;
    for(int i=0; i<k; i++) {
        scanf("%d%d", &p, &q);
        conflict[p][q] = 1;
        conflict[p][p] = 1;
        conflict[q][p] = 1;
        conflict[q][q] = 1;
    }

    Try(1);
    cout << res << "\n";

    return 0;
}
