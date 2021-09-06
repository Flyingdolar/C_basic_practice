#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

int main(){
    int n, x, diver;
    int remainder = 0;
    printf("大數有幾位數：");
    scanf("%d",&n);
    printf("除數是：");
    scanf("%d",&diver);
    printf("請輸入大數數字：");
    while(n--){
        scanf("%1d",&x);
        remainder = (remainder * 10 + x) % diver;
    }
    if (remainder){
        printf("有餘數，餘數為%d\n", remainder);
    }else{
        printf("整除，餘數為0\n");
    }
    return 0;
}