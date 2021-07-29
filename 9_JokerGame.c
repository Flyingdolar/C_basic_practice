#include <stdio.h>
#include <stdbool.h>
#include <stdint.h>

int main(int argc, char const *argv[])
{
    // Input
    int card1, card2, host, cardTol;
    printf("請輸入莊家與自己的牌點數（自己，莊家，自己）：");
    scanf("%d %d %d",&card1 ,&host ,&card2);

    bool isSoft, canSplit;
    int state = 0; // Set ht as 0, sp as 1, st as 2, dd as 3

    // Sampling & Preset
    isSoft = (card1 == 1 || card2 == 1);
    canSplit = (card1 == card2);

    if (card1 >= 10)
        card1 = 10;
    if (card2 >= 10)
        card2 = 10;
    if (host == 1)
        host += 10;
    
    cardTol = card1 +card2;

    // Judgement
    if (canSplit)
    {
        if (cardTol <= 2 || cardTol >= 16){
            if (cardTol == 20){
                state += 1; // Stand
            }else if (cardTol == 18 && (host == 7 || host >= 9)){
                state += 1; // Stand
            }
            state++; // Split
        }else if ((cardTol <= 6 || cardTol == 14) && host <= 7){
            state += 1; // Split
        }else if (cardTol == 8 && (host == 5 || host == 6)){
            state += 1; // Split
        }else if (cardTol >= 12 && host <= 6){
            state += 1; // Split
        }else if (cardTol == 10 && host <= 9){
            state += 3; // Double Down
        }
    }
    else if (isSoft)
    {
        if (cardTol >= 9){
            state += 2; // Stand
        }else if (cardTol == 8 && (host == 2 || host == 7 || host == 8)){
            state += 2; // Stand
        }else if (host == 5 || host == 6){
            state += 3; // Double Down
        }else if (host == 4 && cardTol >= 5){
            state += 3; // Double Down
        }else if (host == 3 && cardTol >= 7){
            state += 3; // Double Down
        }
    }
    else
    {
        if (cardTol >= 17){
            state += 2; // Stand
        }else if (cardTol >= 12 && host <= 6){
            state += 2; // Stand
            if (cardTol == 12 && host <= 3){
                state -= 2; // Hit
            }
        }else if (cardTol == 11 && host <= 10){
            state += 3; // Double Down
        }else if (cardTol == 10 && host <= 9){
            state += 3; // Double Down
        }else if (cardTol == 9 && host >= 3 && host <= 6){
            state += 3; // Double Down
        }
    }

    // Output
    switch (state){
        case 0:
            printf("判斷結果為 HIT ，應該拿牌\n");
            break;
        case 1:
            printf("判斷結果為 SPLIT ，應該拆牌\n");
            break;
        case 2:
            printf("判斷結果為 STAND ，應該停牌\n");
            break;
        case 3:
            printf("判斷結果為 DDOWN ，應該加注\n");
            break;
    }

    return 0;
}
