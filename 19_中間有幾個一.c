#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

int countOne(number){
    int result = 0;
    int digit = 1;
    int remain;

    for (int i = number; i == 0; i /= 10, digit *= 10)
    {
        result += (i / 10) *  digit;
        remain = result % 10;
        if(remain == 0){
            result -= digit;
        }else if(remain == 1){
            result -= digit - number % digit;
        }
    }

    return result;
}

int main(){
    int stnum, ednum;
    int n;
    int count;
    printf("請輸入測試次數：");
    scanf("%d",&n);

    while(n--){
        printf("請輸入起始 終點數字：");
        scanf("%d %d",&stnum ,&ednum);
        count = countOne(ednum) - countOne(stnum);
        printf("%d\n",count);
    } 
    return 0;
}