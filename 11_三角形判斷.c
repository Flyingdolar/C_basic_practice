#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <stdbool.h>

int main(int argc, char const *argv[])
{
    // Input
    int x1, x2, x3, y1, y2, y3;
    printf("請輸入第一個點 x y 座標：");
    scanf("%d %d", &x1, &y1);
    printf("請輸入第二個點 x y 座標：");
    scanf("%d %d", &x2, &y2);
    printf("請輸入第三個點 x y 座標：");
    scanf("%d %d", &x3, &y3);

    // Preset
    int lineA, lineB, lineC;
    lineA = (x2-x1)*(x2-x1) + (y2-y1)*(y2-y1);
    lineB = (x3-x2)*(x3-x2) + (y3-y2)*(y3-y2);
    lineC = (x3-x1)*(x3-x1) + (y3-y1)*(y3-y1);

    int angA, angB, angC;
    angA = lineA - lineB - lineC;
    angB = lineB - lineA - lineC;
    angC = lineC - lineA - lineB;

    lineA = lineA ^ (1/2);
    lineB = lineB ^ (1/2);
    lineC = lineC ^ (1/2);

    bool isTriangle = lineA - lineB - lineC >= 0 && lineB - lineA - lineC >= 0 && lineC - lineA - lineB >= 0;

    // Judging
    if(isTriangle){
        printf("這不是一個三角形！");
    } else if (angA > 0 || angB > 0 || angC > 0){
        printf("此三角形為「鈍角三角形」\n");
    } else if (angA == 0 || angB == 0 || angC == 0){
        printf("此三角形為「直角三角形」\n");
    } else {
        printf("此三角形為「銳角三角形」\n");
    }
    return 0;
}
