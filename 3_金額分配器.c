#include <stdio.h>

int main()
{
    int money = 0;
    int remainder, quotient;
    printf("要將多少錢平分給3個人呢？\n");
    printf("請輸入差距的金額(正負皆可)：");
    scanf("%d", &money);
    remainder = money % 3;
    remainder = (remainder + 3) % 3;
    quotient = (money - remainder) / 3;
    printf("每個人 %d 元，剩下 %d 元\n", quotient, remainder);
    return 0;
}