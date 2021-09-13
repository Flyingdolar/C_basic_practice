#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

int countOne(number){
    int result = 0;
    int digit = 1;
    int judge, storage;

    storage = number;
    while(storage)
    {
        judge = storage % 10;
        storage /= 10;
        result += storage * digit;
        if (judge > 1){
            result += digit;
        }else if(judge == 1){
            result += (number % digit) + 1;
        }
        digit *= 10;
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
        printf("請輸入 起始數字 終點數字：");
        scanf("%d %d",&stnum ,&ednum);
        count = countOne(ednum) - countOne(stnum-1);
        printf("數字 1 在這段區間總共出現 %d 次\n",count);
    } 
    return 0;
}