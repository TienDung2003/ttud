#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 1;

struct Point {
    int x, y;
    Point():x(0), y(0) {}
    Point(int x, int y) : x(x), y(y) {}
};

Point P[N];
int n;
vector<Point> C;
Point O; // Gốc

// Hàm tính khoảng cách bình phương giữa hai điểm
long long dist2(Point &a, Point &b) {
    long long x = a.x - b.x;
    long long y = a.y - b.y;
    return 1LL * x * x + 1LL * y * y;
}

// Hàm tính tích có hướng (cross product) của 2 vector (O, A) và (O, B)
long long cross_product(Point &O, Point &A, Point &B) {
    long long xa = A.x - O.x;
    long long ya = A.y - O.y;
    long long xb = B.x - O.x;
    long long yb = B.y - O.y;
    return 1LL * xa * yb - 1LL * ya * xb;
}

// So sánh hai điểm A, B theo góc cực với gốc O
bool cmp(Point& A, Point& B) {
    long long cp = cross_product(O, A, B);
    return cp == 0 ? dist2(O, A) < dist2(O, B) : cp > 0;
}

// Hàm kiểm tra hướng quay của 3 điểm (a, b, c)
// Trả về 1 nếu quay trái, -1 nếu quay phải, 0 nếu 3 điểm thẳng hàng
int ccw(Point &a, Point &b, Point &c) {
    long long cp = cross_product(a, b, c);
    return cp == 0 ? 0 : (cp < 0 ? -1 : 1);
}

// Kiểm tra xem hai điểm c, d có nằm cùng phía của đoạn thẳng (a, b)
bool same_side(Point &a, Point &b, Point &c, Point &d) {
    int sc = ccw(a, b, c);
    int sd = ccw(a, b, d);
    return sc * sd >= 0;
}

// Hàm tính bao lồi
void computeConvexHull(Point* P, int n) {
    C.clear();
    int k = 0;
    // Tìm điểm có toạ độ y nhỏ nhất (hoặc trái nhất nếu y bằng nhau)
    for (int i = 1; i < n; i++) {
        if (P[i].y < P[k].y || (P[i].y == P[k].y && P[i].x < P[k].x))
            k = i;
    }
    swap(P[0], P[k]); // Đưa điểm có toạ độ thấp nhất về đầu
    O = P[0]; // Cập nhật gốc
    sort(P + 1, P + n, cmp); // Sắp xếp các điểm còn lại theo góc cực
    C.push_back(P[0]);
    C.push_back(P[1]);
    for (int i = 2; i < n; i++) {
        // Loại bỏ các điểm không cần thiết để tạo thành bao lồi
        while (C.size() > 1 && ccw(C[C.size() - 2], C[C.size() - 1], P[i]) <= 0)
            C.pop_back();
        C.push_back(P[i]);
    }
}

// Hàm kiểm tra xem điểm T có nằm trong bao lồi hay không
int checkInSideConvexHull(vector<Point> P, Point& T) {
    int last = P.size() - 1;
    if (same_side(P[0], P[1], P[last], T) && same_side(P[0], P[last], P[1], T)) {
        int l = 1, r = P.size() - 1;
        while (r - l > 1) {
            int mid = (l + r) >> 1;
            if (same_side(P[0], P[mid], P[last], T)) l = mid;
            else r = mid;
        }
        if (!same_side(P[l], P[r], P[0], T)) return 0;
        else return 1;
    }
    return 0;
}

int main() {
    scanf("%d", &n);
    // Đọc các điểm
    for (int i = 0; i < n; i++) {
        scanf("%d%d", &(P[i].x), &(P[i].y));
    }

    // Tính bao lồi
    computeConvexHull(P, n);

    int res = 1;
    // Nếu bao lồi không chứa tất cả các điểm thì kết quả là 0
    //if (C.size() != n) res = 0;

    // Đọc số lượng các điểm cần kiểm tra
    int K;
    scanf("%d", &K);
    for (int k = 1; k <= K; k++) {
        int x, y;
        scanf("%d%d", &x, &y);
        Point p(x, y);
        //if (res == 1)
            res = checkInSideConvexHull(C, p);
        printf("%d\n", res);
    }
    return 0;
}
