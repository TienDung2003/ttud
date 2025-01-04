/*Trong thế giới huyền bí của vương quốc An Lạc, huyền thoại kể về một lời nguyền cổ xưa mà chỉ những kẻ dũng cảm nhất mới có thể phá vỡ.
Vương quốc này có những kho báu bí ẩn, mỗi kho chứa một lượng vàng khổng lồ ciđược đặt tại các vị trí kỳ diệu có toạ độ (xi, yi).
Những người đi tìm kho báu chỉ có thể bắt đầu hành trình từ cổng thành cổ tại (0,0) và theo một quy tắc đặc biệt: họ chỉ được phép di chuyển về phía mặt trời mọc -
theo hướng không giảm của cả hai toạ độ x và y - để tìm đến các kho báu.
Điều này nghĩa là từ kho báu tại (xi, yi), người ta chỉ có thể tiếp tục hành trình đến kho báu (xj, yj) nếu xi ≤ xj và yi ≤ yj.
Kẻ tìm kho báu phải sắp xếp một lộ trình khôn ngoan để thu thập được nhiều vàng nhất,
nhưng cần phải nhớ rằng, lời nguyền sẽ chỉ cho phép họ đi theo hướng mặt trời mọc như đã mô tả.
Dữ liệu vào:
Dòng thứ nhất chứa số nguyên dương n là số lượng kho báu (1 ≤ n ≤ 10
3
).
Trong n dòng tiếp theo, mỗi dòng chứa hai số nguyên dương xi, yi, ci (1 ≤ xi, yi, ci ≤ 10
9
) là toạ độ và lượng vàng của kho báu thứ i, i = 1, 2, …, n.
Kết quả:
Ghi ra một số nguyên duy nhất là tổng lượng vàng lớn nhất có thể tìm được.*/
#include <bits/stdc++.h>
using namespace std;

struct Treasure {
    int x, y, gold, index;
};

bool compare(const Treasure &a, const Treasure &b) {
    if (a.x == b.x) return a.y < b.y;
    return a.x < b.x;
}

int main() {
    int n;
    cin >> n;
    vector<Treasure> treasures(n);
    pair<int, int> inde[n];
    for (int i = 0; i < n; ++i) {
        cin >> treasures[i].x >> treasures[i].y >> treasures[i].gold;
        treasures[i].index = i + 1;
        inde[i+1]={treasures[i].x,treasures[i].y}; // Lưu chỉ số ban đầu để truy vết
    }

    // Sắp xếp theo x, nếu x bằng nhau thì theo y
    sort(treasures.begin(), treasures.end(), compare);

    // DP và mảng truy vết
    vector<long long> dp(n);
    vector<int> prev(n, -1); // -1: không có kho báu trước đó
    long long result = 0;
    int best_end = -1;

    for (int i = 0; i < n; ++i) {
        dp[i] = treasures[i].gold;
        for (int j = 0; j < i; ++j) {
            if (treasures[j].x <= treasures[i].x && treasures[j].y <= treasures[i].y) {
                if (dp[i] < dp[j] + treasures[i].gold) {
                    dp[i] = dp[j] + treasures[i].gold;
                    prev[i] = j;

                }
            }
        }
        if (result < dp[i]) {
            result = dp[i];
            best_end = i;
        }
    }

    // Truy vết đường đi
    vector<int> path;
    while (best_end != -1) {
        path.push_back(treasures[best_end].index);
        best_end = prev[best_end];
    }
    reverse(path.begin(), path.end());

    // In kết quả
    cout << result << endl; // Tổng lượng vàng lớn nhất
    for (int i : path) {
        //cout << i << " "<<endl; // Chỉ số các kho báu trong đường đi
        //cout << inde[i].first<<" "<< inde[i].second<<endl;
    }
    cout << endl;

    return 0;
}
