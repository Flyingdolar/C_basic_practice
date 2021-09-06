#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>

int main(int argc, char const *argv[])
{
    // Input
    int staPoint, movPoint;
    printf("請輸入「起始點」與「擲出點數」:");
    scanf("%d %d", &staPoint, &movPoint);

    // Step Process
    if (movPoint == 2)
    {
        printf("Special value!\n");
        movPoint = (movPoint) * 3 + 2;
    }else if(movPoint > 4){
        if(movPoint % 2)
            movPoint = movPoint - 4;
        else
            movPoint = movPoint / 2;
    }else{
        movPoint = 5;
    }
    printf("移動步數為 %d\n", movPoint);

    // Point Process
    staPoint = staPoint + movPoint;
    bool upstairs, downstairs;
    upstairs = ((staPoint - 3) * (staPoint - 4) >= 0);
    downstairs = ((staPoint % 5) == 0);
    staPoint = staPoint * ((upstairs + 1) / (downstairs + 1));

    if(upstairs)
        printf("上升樓梯，點數乘以二\n");
    if(downstairs)
        printf("下降樓梯，點數除以二\n");

    printf("最終抵達位置為 %d\n",staPoint);
    return 0;
}
