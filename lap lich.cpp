//Giám đốc bệnh viện muốn lập kế hoạch làm việc cho một y tá trong khoảng thời gian nhất định là N ngày liên tiếp 1,..., N.
//Do chính sách của bệnh viện, mỗi y tá không thể làm việc tất cả các ngày 1,..., N. Thay vào đó, phải có những ngày nghỉ để y tá cần nghỉ ngơi.
//Kế hoạch làm việc là một chuỗi các khoảng thời gian làm việc không liên tục.
//Khoảng thời gian làm việc của một y tá được định nghĩa là một chuỗi các ngày liên tiếp mà y tá phải làm việc
//và độ dài của khoảng thời gian làm việc là số ngày liên tiếp của khoảng thời gian làm việc đó. Bệnh viện áp đặt hai ràng buộc:
//Mỗi y tá chỉ được nghỉ một ngày giữa hai ca làm việc liên tiếp. Điều đó có nghĩa là nếu y tá nghỉ hôm nay thì ngày mai phải làm việc (1)
//Độ dài của mỗi giai đoạn làm việc phải lớn hơn hoặc bằng K1và nhỏ hơn hoặc bằng K2(2)
//Giám đốc bệnh viện muốn biết có bao nhiêu phương án làm việc có thể thỏa mãn ràng buộc trên?
#include <bits/stdc++.h>
using namespace std;

const int MAX = 2000;
int n, k1, k2;

void solve()
{
    int S0[MAX];
    int S1[MAX];
    for(int i=1; i<=n; i++) {
        S0[i] = 0;
        S1[i] = 0;
    }
    S0[1] = 1;
    S1[k1] = 1;
    S0[0] = 1; //linh canh
    for(int i=k1+1; i<=n; i++) {
        S0[i] = S1[i-1];
        S1[i] = 0;
        for(int j=k1; j<=k2; j++) {
            if(i-j >= 0) {
                S1[i] += S0[i-j];
            }
        }
    }
    int res = S0[n] + S1[n];
    cout << res << "\n";
}

int main()
{
    scanf("%d%d%d", &n, &k1, &k2);
    solve();
}
