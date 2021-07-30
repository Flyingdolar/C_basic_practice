#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>

int main(int argc, char const *argv[])
{
    int allStone, pickStone, round;
    printf("一開始有幾顆石頭：");
    scanf("%d",&allStone);
    printf("一人一次最多能拿幾顆石頭：");
    scanf("%d",&pickStone);

    pickStone = pickStone + 1;
    round = allStone % pickStone;
    if (round == 0){
        printf("後手獲勝，每次拿取石頭數量為 %d - 對手拿的石頭數則可勝利\n",pickStone);
    }else{
        printf("先手獲勝，第一次拿 %d 顆石頭\n",round);
    }

    return 0;
}