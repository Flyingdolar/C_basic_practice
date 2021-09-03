#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int inCircle(int x, int y,  int r, int testx, int testy)
{
    testx = (testx - x) * (testx - x);
    testy = (testy - y) * (testy - y);
    r = r * r;

    if(r >= (testx + testy))
        return 1;
    else
        return 0;
}

int main(){
    int x1, y1, r1;
    int x2, y2, r2;
    int x3, y3, r3;
    int testx, testy;
    int resultOne, resultTwo, resultThree;

    int times;
    printf("請輸入欲測試次數：");
    scanf("%d",&times);

    while(times){
        printf("請輸入第一個圓的資訊（Ｘ座標 Ｙ座標 Ｒ半徑）：");
        scanf("%d %d %d",&x1,&y1,&r1);
        printf("請輸入第二個圓的資訊（Ｘ座標 Ｙ座標 Ｒ半徑）：");
        scanf("%d %d %d",&x2,&y2,&r2);
        printf("請輸入第三個圓的資訊（Ｘ座標 Ｙ座標 Ｒ半徑）：");
        scanf("%d %d %d",&x3,&y3,&r3);

        resultOne = 0;
        resultTwo = 0;
        resultThree = 0;

        for (int i = (x1-r1); i <= (x1+r1); i++){
            for (int j = (y1-r1); j <= (y1+r1); j++){
                if (inCircle(x1,y1,r1,i,j)){
                    if(inCircle(x2,y2,r2,i,j) && inCircle(x3,y3,r3,i,j)){
                        resultThree++;
                    }else if(inCircle(x2,y2,r2,i,j) || inCircle(x3,y3,r3,i,j)){
                        resultTwo++;
                    }else{
                        resultOne++;
                    }
                }
            }
        }

        for (int i = (x2-r2); i <= (x2+r2); i++){
            for (int j = (y2-r2); j <= (y2+r2); j++){
                if (inCircle(x2,y2,r2,i,j)){
                    if(inCircle(x1,y1,r1,i,j) && inCircle(x3,y3,r3,i,j)){
                        resultThree++;
                    }else if(inCircle(x1,y1,r1,i,j) || inCircle(x3,y3,r3,i,j)){
                        resultTwo++;
                    }else{
                        resultOne++;
                    }
                }
            }
        }

        for (int i = (x3-r3); i <= (x3+r3); i++){
            for (int j = (y3-r3); j <= (y3+r3); j++){
                if (inCircle(x3,y3,r3,i,j)){
                    if(inCircle(x2,y2,r2,i,j) && inCircle(x1,y1,r1,i,j)){
                        resultThree++;
                    }else if(inCircle(x2,y2,r2,i,j) || inCircle(x1,y1,r1,i,j)){
                        resultTwo++;
                    }else{
                        resultOne++;
                    }
                }
            }
        }

        resultTwo = resultTwo / 2;
        resultThree = resultThree /3;

        printf("恰巧被一個圓圍住的格點：%d\n", resultOne);
        printf("恰巧被兩個圓圍住的格點：%d\n", resultTwo);
        printf("恰巧被三個圓圍住的格點：%d\n", resultThree);

        times -= 1;
    }
    return 0;
}
