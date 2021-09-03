#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>

int main(int argc, char const *argv[])
{
    // Input
    int originX, originY;
    printf("請輸入要判斷的點位置（Ｘ座標 Ｙ座標）：");
    scanf("%d %d", &originX, &originY);

    int x1, y1, x2, y2, x3, y3, x4, y4;
    printf("請輸入矩形的四個點的座標（逆時針順序）\n");
    printf("第一個點座標（Ｘ座標 Ｙ座標）：");
    scanf("%d %d", &x1, &y1);
    printf("第二個點座標（Ｘ座標 Ｙ座標）：");
    scanf("%d %d", &x2, &y2);
    printf("第三個點座標（Ｘ座標 Ｙ座標）：");
    scanf("%d %d", &x3, &y3);
    printf("第四個點座標（Ｘ座標 Ｙ座標）：");
    scanf("%d %d", &x4, &y4);

    // Organize
    x1 -= originX;
    y1 -= originY;
    x2 -= originX;
    y2 -= originY;
    x3 -= originX;
    y3 -= originY;
    x4 -= originX;
    y4 -= originY;

    // Judgement
    int crossArea1, crossArea2, crossArea3, crossArea4;
    crossArea1 = (x1 * y2) - (x2 * y1);
    crossArea2 = (x2 * y3) - (x3 * y2);
    crossArea3 = (x3 * y4) - (x4 * y3);
    crossArea4 = (x4 * y1) - (x1 * y4);
    printf("%d %d %d %d", crossArea1, crossArea2, crossArea3, crossArea4);

    // Output
    if (crossArea1 == 0 || crossArea2 == 0 || crossArea3 == 0 || crossArea4 == 0){
        printf("原點在所圍矩形的邊線上！\n");
    } else if (crossArea1 < 0 || crossArea2 < 0 || crossArea3 < 0 || crossArea4 < 0){
        printf("原點在所圍矩形的範圍外！\n");
    } else {
        printf("原點在所圍矩形的範圍內！\n");
    }

    return 0;
}
