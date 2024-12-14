//Cho một dãy số nguyên n a=a1, N
//Một dãy con của a bao gồm các phần tử liền kề của a (ví dụ, ai, ai+1, aj).
//Trọng số của một dãy con được định nghĩa là tổng các phần tử của nó. Một dãy con được gọi là dãy con chẵn nếu trọng số của nó là chẵn.
//Tìm dãy con chẵn của một dãy con có trọng số lớn nhất.
//sum[i] la tong tien to
//sum_chan la tong tien to chan nho nhan duoc ghi nhan, tuong tu voi sum_le

#include <bits/stdc++.h>
using namespace std;

const int MAX = 1e6 + 5;
int n;
long long a[MAX], res = INT_MIN;
long long sum[MAX], even_sum=0, odd_sum = INT_MIN;

long long solve()
{
    for(int i=1; i<=n; i++) {
        sum[i] = sum[i-1] + a[i];
        if(sum[i]%2 == 0) {
            res = max(res, sum[i]-even_sum);
            even_sum = min(even_sum, sum[i]);
        }
        else {
            if(odd_sum == INT_MIN) odd_sum = sum[i];
            else {
                res = max(res, sum[i]-odd_sum);
                odd_sum = min(odd_sum, sum[i]);
            }
        }
    }
    return res;
}

int main()
{
    scanf("%d", &n);
    for(int i=1; i<=n; i++) cin >> a[i];
    sum[0] = 0; //linh canh
    long long result = solve();
    if(result == INT_MIN) cout << "NOT_FOUND\n";
    else cout << result << "\n";

    return 0;
}
