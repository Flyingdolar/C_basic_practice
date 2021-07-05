#include <stdio.h>

int main()
{
    int weight = 0;
    printf("體重機壞掉了，他總是會在最前面加一位數 1\n");
    printf("請輸入您測量的體重：");
    scanf("1%d", &weight);
    printf("您正確的體重是：%d\n", weight);
    return 0;
}