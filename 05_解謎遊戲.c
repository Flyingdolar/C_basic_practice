#include <stdio.h>

int main(int argc, char const *argv[])
{
    // Input
    int n;              // 1 <=   n   <= 2 * 10^5
    int r1, r2, ans;    // 0 <= r1 r2 <= 2^30
    int h1, m1, s1;     // 0 <= h1 h2 <= 24
    int h2, m2, s2;     // 0 <= m1 m2 <= 60
                        // 0 <= s1 s2 <= 60

    // Read
    printf("請輸入規定臨界值 n ：");
    scanf("%d", &n);
    printf("請輸入區間 R1 ~ R2 (r1 r2)：");
    scanf("%d %d",&r1, &r2);
    printf("請輸入開始時間(h m s)：");
    scanf("%d %d %d",&h1, &m1, &s1);
    printf("請輸入結束時間(h m s)：");
    scanf("%d %d %d",&h2, &m2, &s2);

    // Overflow 1
    n = n + 1;
    ans = r1 - r2;
    ans = (ans + (1000 * n)) % n;

    h1 = h2 - h1;
    m1 = m2 - m1;
    s1 = s2 - s1;

    // Overflow 2
    ans = ans + (h1 * 3600) + (m1 * 60) + s1;
    ans = (ans + (1000 * n)) % n;

    // Output
    printf("所得的八位數密碼是：%08d\n", ans);

    return 0;           
}
