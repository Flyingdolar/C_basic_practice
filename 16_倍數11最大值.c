#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int main(){
    int ZeroAmount;
    int OneAmount;
    int n, times, input;

    printf("欲測試次數：");
    scanf("%d",&times);
    while(times--)
    {
        ZeroAmount = 0;
        OneAmount = 0;
        printf("要輸入數字的是幾位數：");
        scanf("%d",&n);
        printf("要輸入數字：");
        while (n--){
            scanf("%1d",&input);
            if(input){
                OneAmount++;
            }else{
                ZeroAmount++;
            }
        }
        if(!OneAmount){
            printf("你輸入的數字為0，不可能為11的倍數\n");
        }else if(OneAmount % 2){
            if(OneAmount < 11 || ZeroAmount < 10){
                printf("不可能為11的倍數\n");
            }else{
                while (OneAmount-- -11){
                    printf("1");
                }
                printf("101010101010101010101");
                while (ZeroAmount-- -10){
                    printf("0");
                }
            }
        }else{
            while (OneAmount--){
                printf("1");
            }
            while (ZeroAmount--){
                printf("0");
            }
        }
        printf("\n");
    }
}