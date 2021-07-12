#include <stdio.h>

int main()
{
    int date, month, year;
    printf("請輸入今天日期(日/月/年)\n");
    scanf("%d/%d/%d",&date ,&month ,&year);
    printf("Hello World!\n");
    printf("今天是 %d 年 %02d 月 %02d 日\n",year ,month, date);
    return 0; 
}